/**
 *    author: Jingbo Su
 *    created: 29/10/2021
 **/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Car {
  int num;
  int beginTime;
  int endTime;

  Car() : num(0), beginTime(0), endTime(0) {}

  Car(int a, int b, int c) : num(a), beginTime(b), endTime(c) {}

  Car(int a, int b) : num(a), beginTime(0), endTime(b) {}

  Car(const Car &car1) {
    this->num = car1.num;
    this->beginTime = car1.beginTime;
    this->endTime = car1.endTime;
  }

  Car &operator=(const Car &obj) {
    if (this == &obj) return *this;
    this->num = obj.num;
    this->beginTime = obj.beginTime;
    this->endTime = obj.endTime;
    return *this;
  }
};

class queue {
 public:
  struct Container {
    Container *next;
    Container *prev;
    Car car;

    Container() : next(nullptr), prev(nullptr) {}

    explicit Container(Car &car1) : next(nullptr), prev(nullptr), car(car1) {}

    Container(const Container &q) { *this = q; }

    Container &operator=(const Container &obj) {
      if (this == &obj) return *this;
      this->car = obj.car;
      this->next = nullptr;
      this->prev = nullptr;
      return *this;
    }
  };

  typedef Container _Queue;
  typedef Container *_Q;

 public:
  void init() noexcept {
    _q = new _Queue();
    _q->next = _q;
    _q->prev = _q;
    size = 0;
  }

  bool isEmpty() const noexcept { return !size; }

  void Push(Car C) {
    //        会产生野指针
    //        _Queue node(C);
    //        _Q _node = &node;
    _Q node = new Container(C);

    _Q ne = _q->next;
    _Q pr = _q;
    node->next = ne;
    ne->prev = node;
    node->prev = pr;
    pr->next = node;

    ++this->size;
  }

  void Pop() {
    _Q t = _q;
    if (this->isEmpty()) return;
    _Q pr = t->prev;
    t->prev = pr->prev;
    pr->prev->next = t;

    --this->size;
  }

  Car Top() {
    if (this->isEmpty()) exit(0);
    return _q->prev->car;
  }

  bool findInQueue(Car C) {
    if (this->isEmpty()) return false;
    _Q ne = _q->next;
    while (ne != _q) {
      if (ne->car.num == C.num) return true;
      ne = ne->next;
    }
    return false;
  }

 private:
  _Q _q;
  int size;
};

typedef pair<int, float> pif;

bool findInSack(const vector<Car> &stk, Car &car) {
  for (auto &i : stk) {
    if (i.num == car.num) {
      car.beginTime = i.beginTime;
      return true;
    }
  }
  return false;
}

int main() {
  int capacity;
  float perPrice;
  cin >> capacity >> perPrice;
  int operation, num, time;
  vector<pif> ans1;
  vector<int> ans2;
  vector<int> ans3;

  // Initialize stack;
  vector<Car> stk1, stk2;
  function<void(vector<Car> &, Car &)> enStack =
      [](vector<Car> &stk, const Car &car) { stk.emplace_back(car); };
  function<void(vector<Car> &)> deStack = [](vector<Car> &stk) {
    stk.pop_back();
  };
  //
  // Initialize queue;
  queue q;
  q.init();

  while (cin >> operation >> num >> time, operation || num || time) {
    if (!operation) {
      // Create the parking car
      // car.num, car.beginTime
      Car car(num, time, 0);
      // Push in stack
      if (static_cast<int>(stk1.size()) < capacity) enStack(stk1, car);
      // Push in queue
      else
        q.Push(car);
    } else if (operation == 1) {
      // car.num, car.endTime
      Car car(num, time);

      // Find in the stack
      if (findInSack(stk1, car)) {
        float price = 0.0;
        // Move cars behind it and re_enter
        for (int i = static_cast<int>(stk1.size()) - 1; ~i; --i) {
          if (stk1[i].num == car.num) {
            int deTime = car.endTime - car.beginTime;
            price = static_cast<float>(deTime) * perPrice;
            // TODO: push the result to the answer vector(part. 1)
            ans1.emplace_back(make_pair(car.num, price));
            deStack(stk1);
            break;
          }
          enStack(stk2, stk1[i]);
          deStack(stk1);
        }
        for (int i = static_cast<int>(stk2.size()) - 1; ~i; --i) {
          enStack(stk1, stk2[i]);
          deStack(stk2);
        }

        // If the queue is not empty, pop the top and push into the stack
        if (!q.isEmpty()) {
          auto tc = q.Top();
          tc.beginTime = car.endTime;
          enStack(stk1, tc);
          q.Pop();
        }
      }

      // Find in the queue
      else if (q.findInQueue(car)) {
        while (q.Top().num != car.num) {
          auto tc = q.Top();
          q.Pop();
          q.Push(tc);
        }
        // q.top == car
        q.Pop();
      }
    }
  }

  // TODO: print the car(s) in the park(part.2)
  for (auto &i : stk1) {
    ans2.emplace_back(i.num);
  }

  // TODO: print the car(s) in the road(part.3)
  while (!q.isEmpty()) {
    auto tc = q.Top();
    ans3.emplace_back(tc.num);
    q.Pop();
  }

  // Print the result
  auto printInt = [](const int &n) { cout << n << ' '; };
  auto printPair = [](const pif &pp) {
    printf("%d %.2f\n", pp.first, pp.second);
  };

  for_each(ans1.begin(), ans1.end(), printPair);
  for_each(ans2.begin(), ans2.end(), printInt);
  cout << endl;
  for_each(ans3.begin(), ans3.end(), printInt);
  cout << endl;

  return 0;
}