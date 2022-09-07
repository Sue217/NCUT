/*
 *      学术与工程实践I（计算机）
 *      药品供销管理系统
 *      Tools: Clion / VSCode
 *      Environment: macOS 10.15 / CentOS 7
 *      Language: C++
 *      Version: -std=c++ 11 or Later
 *      Author: Jingbo Su
 *      Begin Date: Sat Aug/14/2021
 *      Finish Date: Sat Aug/21/2021
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unistd.h>
#include <utility>
#include <iomanip>
#include <ctime>

using namespace std;
/*  Attention: "NOLINT" is used to prevent errors on CLion  */

// Loading Bar
void progressBar()
{
    cout << "* Loading" << endl;
    sleep(2);
    cout << "[##########        ]  "
         << "(1/2)" << endl;
    sleep(1);
    cout << "[##################]  "
         << "(2/2)" << endl;
}

class Medicine
{
private:
    struct medicineMessage
    {
        string number;
        string name;
        string species;
        string manufacture;
        string price;
        string indate;
        string attentionMatters;
        string stock;
    };

    // 文件IO使用
    list<medicineMessage> ioMedicineList;
    string fileBasePath = "medicine_base.dat";

public:
    // First!
    // Put file content into List (Read)
    Medicine()
    {
        ifstream ifstr(fileBasePath, ios::in);
        // Just in case
        if (!ifstr.is_open())
        {
            ofstream tmp(fileBasePath, ios::out);
            if (!tmp.is_open())
            {
                cout << "文件创建失败，退出程序" << endl;
                exit(-1);
            }
            tmp.close();
        }

        system("clear");
        // On Windows
        // system("cls");

        // Open successfully
        cout << "******** 欢迎使用药品供销系统 ********" << endl;
        sleep(1);
        progressBar();
        cout << endl;

        ifstream _ifstr(fileBasePath, ios::in);
        char ch[200];
        medicineMessage msg;

        // Read the empty first line
        _ifstr.getline(ch, sizeof(ch));

        while (!_ifstr.eof())
        {
            _ifstr.getline(ch, sizeof(ch));
            msg.number = ch;
            _ifstr.getline(ch, sizeof(ch));
            msg.name = ch;
            _ifstr.getline(ch, sizeof(ch));
            msg.species = ch;
            _ifstr.getline(ch, sizeof(ch));
            msg.manufacture = ch;
            _ifstr.getline(ch, sizeof(ch));
            msg.price = ch;
            _ifstr.getline(ch, sizeof(ch));
            msg.indate = ch;
            _ifstr.getline(ch, sizeof(ch));
            msg.attentionMatters = ch;
            _ifstr.getline(ch, sizeof(ch));
            msg.stock = ch;

            ioMedicineList.push_back(msg);
        }
        _ifstr.close();

        cout << "文件读取完成" << endl;
        sleep(1);
        cout << endl;
        system("clear");
        // On Windows
        // system("cls");
    }

    bool logMedicineMessage()
    {
        medicineMessage message;
        cout << endl
             << "========= 药品信息录入 =========" << endl;
        cout << "@@@ 若想退出录入请输入\'q\' @@@" << endl
             << endl;
        L1:
        cout << "请输入药品编号：";
        cin >> message.number;
        if (message.number == "q")
        {
            return false;
        }
        for (auto &item: ioMedicineList)
        {
            if (item.number == message.number)
            {
                cout << endl
                     << "药品重复录入，请检查录入药品的编号！" << endl
                     << endl;
                goto L1;
            }
        }

        // Log message until return false
        cout << "请输入药品名称：";
        cin >> message.name;
        if (message.name == "q")
        {
            return false;
        }
        cout << "请输入药品种类：";
        cin >> message.species;
        if (message.species == "q")
        {
            return false;
        }
        cout << "请输入药品生产厂家：";
        cin >> message.manufacture;
        if (message.manufacture == "q")
        {
            return false;
        }
        cout << "请输入药品价格：";
        cin >> message.price;
        if (message.price == "q")
        {
            return false;
        }
        cout << "请输入药品有效日期（yyyy/mm/dd）：";
        cin >> message.indate;
        if (message.indate == "q")
        {
            return false;
        }
        cout << "请输入药品注意事项：";
        cin >> message.attentionMatters;
        if (message.attentionMatters == "q")
        {
            return false;
        }
        cout << "请输入药品库存量（初始为0）：";
        cin >> message.stock;
        if (message.stock == "q")
        {
            return false;
        }
        cout << endl;

        ioMedicineList.push_back(message);

        ofstream ofstr(fileBasePath, ios::app);
        ofstr << endl
              << message.number << endl
              << message.name << endl
              << message.species << endl
              << message.manufacture << endl
              << message.price << endl
              << message.indate << endl
              << message.attentionMatters << endl
              << message.stock;

        ofstr.close();
        return true;
    }


private:
    string fileDealPath = "medicine_deal.dat";
    struct intoStorageMessage
    {
        string medicineName;
        string medicineNum;
        string intoStoragePerPrice;
        string intoStorageNum;
        string intoStoragePrice; // intoStoragePrice = intoStoragePerPrice * intoStorageNum
        string intoStorageDate;
        string intoStoragePerson;
        string intoStorageType;
    };

public:
    bool intoStorageMedicine()
    {
        intoStorageMessage iSM;
        cout << "========= 药品入库 =========" << endl;
        cout << "@@@ 若想要退出请输入\'q\' @@@" << endl
             << endl;
        L1:
        cout << "请输入入库药品编号：";
        cin >> iSM.medicineNum;
        if (iSM.medicineNum == "q")
        {
            return false;
        }
        bool flag = true;
        for (auto &item: ioMedicineList)
        {
            // Find match
            if (item.number == iSM.medicineNum)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "无药品信息，请重新输入" << endl;
            goto L1;
        }

        cout << "请输入入库药品名称：";
        cin >> iSM.medicineName;
        if (iSM.medicineName == "q")
        {
            return false;
        }
        cout << "请输入入库药品单价：";
        cin >> iSM.intoStoragePerPrice;
        if (iSM.intoStoragePerPrice == "q")
        {
            return false;
        }
        cout << "请输入入库药品数量：";
        cin >> iSM.intoStorageNum;
        if (iSM.intoStorageNum == "q")
        {
            return false;
        }
        double perPrice = stod(iSM.intoStoragePerPrice);
        int intoNum = stoi(iSM.intoStorageNum);
        iSM.intoStoragePrice = to_string(static_cast<double>(perPrice * intoNum));
        cout << fixed << showpoint;
        cout << setprecision(3);
        cout << "入库药品金额为：" << static_cast<double>(perPrice * intoNum) << endl;
        cout << "请输入药品入库日期（yyyy/mm/dd）：";
        cin >> iSM.intoStorageDate;
        if (iSM.intoStorageDate == "q")
        {
            return false;
        }

        cout << "请输入入库员姓名：";
        cin >> iSM.intoStoragePerson;
        if (iSM.intoStoragePerson == "q")
        {
            return false;
        }
        cout << "交易类型：采购" << endl;
        iSM.intoStorageType = "采购";


        // Refresh ioMedicineList.stockNum
        // TODO: Refresh the base file
        for (auto &item: ioMedicineList)
        {
            if (item.number == iSM.medicineNum)
            {
                int Stk = stoi(item.stock);
                Stk += intoNum;
                item.stock = to_string(Stk);
            }
        }

        // Write into file

        ofstream ofstr(fileDealPath, ios::app);
        ofstr << endl
              << iSM.medicineName << endl
              << iSM.medicineNum << endl
              << iSM.intoStoragePerPrice << endl
              << iSM.intoStorageNum << endl
              << iSM.intoStoragePrice << endl
              << iSM.intoStorageDate << endl
              << iSM.intoStoragePerson << endl
              << iSM.intoStorageType;

        ofstr.close();

        ofstream _ofstr(fileBasePath, ios::out | ios::trunc);
        _ofstr << endl;
        for (auto &item: ioMedicineList)
        {
            _ofstr << endl
                   << item.number << endl
                   << item.name << endl
                   << item.species << endl
                   << item.manufacture << endl
                   << item.price << endl
                   << item.indate << endl
                   << item.attentionMatters << endl
                   << item.stock;
        }

        _ofstr.close();

        cout << endl;
        progressBar();
        sleep(1);
        cout << endl
             << endl;
        system("clear");
        // On Windows
        // system("cls");
        return true;
    }

private:
    struct outStockMessage
    {
        string medicineName;
        string medicineNum;
        string outStockPerPrice;
        string outStockNum;
        string outStockPrice; // outStockPrice = outStockPerPrice * outStockNum
        string outStockDate;
        string buyer;
        string outStockType;
    };

public:
    bool outStockMedicine()
    {
        outStockMessage oSM;
        cout << "========= 药品销售 =========" << endl;
        cout << "@@@ 如果想要退出输入，请输入\'q\' @@@" << endl;
        L2:
        cout << "请输入销售药品编号：";
        cin >> oSM.medicineNum;
        if (oSM.medicineNum == "q")
        {
            return false;
        }
        bool flag = true;
        int stockNum = 0;
        for (auto &item: ioMedicineList)
        {
            if (item.number == oSM.medicineNum)
            {
                stockNum = stoi(item.stock);
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "无药品信息，请重新输入" << endl;
            goto L2;
        }
        // flag == false
        cout << "请输入购买数量：";
        cin >> oSM.outStockNum;
        if (oSM.outStockNum == "q")
        {
            return false;
        }
        // If it is more than stock?
        int outNum = stoi(oSM.outStockNum);
        if (outNum > stockNum)
        {
            cout << "库存不足，请重新输入" << endl;
            goto L2;
        } else
        {

            cout << "销售药品编号为：" << oSM.medicineNum << endl;

            cout << "请输入销售药品名称：";
            cin >> oSM.medicineName;
            if (oSM.medicineName == "q")
            {
                return false;
            }
            cout << "请输入交易单价：";
            cin >> oSM.outStockPerPrice;
            if (oSM.outStockPerPrice == "q")
            {
                return false;
            }
            cout << "交易数量为：" << outNum << endl;
            oSM.outStockNum = to_string(outNum);
            oSM.outStockPrice = to_string(static_cast<double>(stod(oSM.outStockPerPrice) * outNum));
            cout << fixed << showpoint;
            cout << setprecision(3);
            cout << "交易金额为：" << static_cast<double>(stod(oSM.outStockPerPrice) * outNum) << endl;
            cout << "请输入药品交易日期（yyyy/mm/dd）：";
            cin >> oSM.outStockDate;
            if (oSM.outStockDate == "q")
            {
                return false;
            }

            cout << "请输入购买者姓名：";
            cin >> oSM.buyer;
            if (oSM.buyer == "q")
            {
                return false;
            }

            oSM.outStockType = "销售";
            cout << "交易类型："
                 << "销售" << endl;

            ofstream ofstr(fileDealPath, ios::app);
            ofstr << endl
                  << oSM.medicineName << endl
                  << oSM.medicineNum << endl
                  << oSM.outStockPerPrice << endl
                  << oSM.outStockNum << endl
                  << oSM.outStockPrice << endl
                  << oSM.outStockDate << endl
                  << oSM.buyer << endl
                  << oSM.outStockType;

            ofstr.close();
            for (auto &item: ioMedicineList)
            {
                if (item.number == oSM.medicineNum)
                {
                    stockNum -= outNum;
                    item.stock = to_string(stockNum);
                }
            }

            ofstream _ofstr(fileBasePath, ios::out | ios::trunc);
            _ofstr << endl;
            for (auto &item: ioMedicineList)
            {
                _ofstr << endl
                       << item.number << endl
                       << item.name << endl
                       << item.species << endl
                       << item.manufacture << endl
                       << item.price << endl
                       << item.indate << endl
                       << item.attentionMatters << endl
                       << item.stock;
            }

            _ofstr.close();

            return true;
        }
    }

    // Func.5 Modify or delete the basic information of medicine
    bool modify()
    {
        // species, manufacture, price, indate, attentionMatters can be modified
        // medicineNum, medicineName, medicineStock can not be modified!
        // And the medicine information can not be modified if the medicine have been dealt!

        L0:
        cout << "---------- 修改药品基本信息 ----------" << endl
             << endl;
        cout << "请选择想要进行的操作（修改信息/删除信息）" << endl;
        cout << "     *1 修改药品信息" << endl;
        cout << "     *2 删除药品信息" << endl;
        cout << endl
             << "请输入想要进行的操作（1/2）如果想退出请输入\'q\'" << endl;
        char ops;
        cin >> ops;
        if (ops == '1')
        {
            // Modify
            L1:
            cout << "请输入您想要修改信息的药品编号：";
            string medicineNumber;
            cin >> medicineNumber;
            bool flag = true;
            for (auto &item: ioMedicineList)
            {
                if (item.number == medicineNumber)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "未找到此药品信息，请检查输入" << endl;
                sleep(1);
                goto L1;
            } else
            {
                cout << endl
                     << "请选择您想要修改的药品信息：" << endl;
                cout << "     *1 药品种类" << endl;
                cout << "     *2 生产厂家" << endl;
                cout << "     *3 药品价格" << endl;
                cout << "     *4 有效日期" << endl;
                cout << "     *5 注意事项" << endl
                     << endl;
                L2:
                cout << "请输入您想要修改的药品信息，如果想退出请输入\'q\'：";
                char choice;
                cin >> choice;

                if (choice == '1')
                {
                    cout << "请输入您想修改成的药品种类：";
                    string newMedicineSpecies;
                    cin >> newMedicineSpecies;
                    for (auto &item: ioMedicineList)
                    {
                        if (item.number == medicineNumber)
                        {
                            item.species = newMedicineSpecies;
                        }
                    }
                } else if (choice == '2')
                {
                    cout << "请输入您想修改成的药品生产厂家：";
                    string newMedicineManufacture;
                    cin >> newMedicineManufacture;
                    for (auto &item: ioMedicineList)
                    {
                        if (item.number == medicineNumber)
                        {
                            item.manufacture = newMedicineManufacture;
                        }
                    }
                } else if (choice == '3')
                {
                    cout << "请输入您想修改成的药品价格：";
                    string newMedicinePrice;
                    cin >> newMedicinePrice;
                    for (auto &item: ioMedicineList)
                    {
                        if (item.number == medicineNumber)
                        {
                            item.price = newMedicinePrice;
                        }
                    }
                } else if (choice == '4')
                {
                    cout << "请输入您想修改成的药品有效日期：";
                    string newMedicineIndate;
                    cin >> newMedicineIndate;
                    for (auto &item: ioMedicineList)
                    {
                        if (item.number == medicineNumber)
                        {
                            item.indate = newMedicineIndate;
                        }
                    }
                } else if (choice == '5')
                {
                    cout << "请输入您想修改成的注意事项：";
                    string newMedicineAttentions;
                    cin >> newMedicineAttentions;
                    for (auto &item: ioMedicineList)
                    {
                        if (item.number == medicineNumber)
                        {
                            item.attentionMatters = newMedicineAttentions;
                        }
                    }
                } else if (choice == 'q')
                {
                    cout << "** 正在退出 **" << endl;
                    sleep(1);
                    goto L0;
                } else
                {
                    cout << "输入有误，请检查输入" << endl;
                    goto L2;
                }
            }

            // Modify file
            ofstream ofstr(fileBasePath, ios::out | ios::trunc);
            ofstr << endl;
            for (auto &item: ioMedicineList)
            {
                ofstr << endl
                      << item.number << endl
                      << item.name << endl
                      << item.species << endl
                      << item.manufacture << endl
                      << item.price << endl
                      << item.indate << endl
                      << item.attentionMatters << endl
                      << item.stock << endl;
            }

            ofstr.close();
            cout << "药品信息修改完成！" << endl;
            sleep(1);
            system("clear");
            // On Windows
            // system("cls");
        } else if (ops == '2')
        {
            // TODO: Delete!
            L3:
            cout << "请输入您想要删除药品的编号，如果想要退出请输入\'q\'：";
            bool flag = true;
            string medicineNumber;
            cin >> medicineNumber;

            if (medicineNumber == "q")
            {
                cout << endl;
                sleep(1);
                goto L0;
            }

            // Check whether the medicineNumber has been entered
            for (auto &item: ioMedicineList)
            {
                if (item.number == medicineNumber)
                {
                    flag = false;
                    // Check whether the medicine has not been dealt
                    ifstream ifstr(fileDealPath, ios::in);
                    string ss;
                    while (getline(ifstr, ss))
                    {
                        if (ss == item.number)
                        {
                            flag = true;
                            break;
                        }
                    }

                    break;
                }
            }

            // If flag is true, either the medicine has not been entered or has been dealt
            if (flag)
            {
                cout << "未找到药品信息或药品存在交易记录无法删除，请检查输入！" << endl;
                sleep(1);
                goto L3;
            } else
            {
                auto itr = ioMedicineList.begin();
                while (itr->number != medicineNumber)
                {
                    ++itr;
                }
                // itr -> number = medicineNumber
                ioMedicineList.erase(itr);
                // Refresh the base file now!
                ofstream ofstr(fileBasePath, ios::out | ios::trunc);
                ofstr << endl;
                for (auto &item: ioMedicineList)
                {
                    ofstr << endl
                          << item.number << endl
                          << item.name << endl
                          << item.species << endl
                          << item.manufacture << endl
                          << item.price << endl
                          << item.indate << endl
                          << item.attentionMatters << endl
                          << item.stock;
                }

                ofstr.close();
                cout << "药品删除完成！" << endl;
                sleep(1);
                system("clear");
                // On Windows
                // system("cls");
            }
        } else if (ops == 'q')
        {
            cout << "* 正在更新修改" << endl;
            sleep(1);
            return false;
        }

        return true;
    }

    // Set string double precision to 2 bits
    static string setPrecision(const string &target)
    {
        return target.substr(0, target.size() - 4);
    }

    // Func.6 Output all messages
    void outputAllMessages()
    {
        // Output medicine basic messages
        cout << "---------- 药品基本信息 ----------" << endl
             << endl;
        for (auto &item: ioMedicineList)
        {
            cout << "药品编号：       " << item.number << endl;
            cout << "药品名称：       " << item.name << endl;
            cout << "药品种类：       " << item.species << endl;
            cout << "生产厂家：       " << item.manufacture << endl;
            cout << "药品价格：       " << item.price << endl;
            cout << "药品有效期：     " << item.indate << endl;
            cout << "药品注意事项：    " << item.attentionMatters << endl;
            cout << "药品库存量：      " << item.stock << endl
                 << endl;
        }



        //TODO: Find method to beautify the form!

        cout.setf(ios::left);
        int x, y, z;
        for (int i = 0; i < 97; ++i)cout << '-';
        cout << endl;
        string title = "---------- 药品交易信息 ----------";
        y = static_cast<int> (title.size());
        x = z = (103 - y) / 2;
        if (y & 1)z++;
        cout << '|' << setw(x) << ' ' << title << setw(z + 1) << ' ' << '|';
        cout << endl;
        for (int i = 0; i < 97; ++i)cout << '-';
        cout << endl;
        cout << '|' << setw(3) << ' ' << "药品名称" << setw(4) << ' ' << '|';
        cout << setw(1) << ' ' << "药品编号" << setw(2) << ' ' << '|';
        cout << setw(1) << ' ' << "交易单价" << setw(2) << ' ' << '|';
        cout << setw(1) << ' ' << "交易数量" << setw(2) << ' ' << '|';
        cout << setw(1) << ' ' << "交易金额" << setw(2) << ' ' << '|';
        cout << setw(3) << ' ' << "交易时间" << setw(3) << ' ' << '|';
        cout << setw(3) << ' ' << "交易人员" << setw(3) << ' ' << '|';
        cout << setw(2) << ' ' << "交易方式" << setw(2) << ' ' << '|' << endl;
        for (int i = 0; i < 97; ++i)cout << '-';
        cout << endl;

        readDealFile();
        for (auto &item: medicineTradeList)
        {
            y = static_cast<int> (item.medicineName.size());
            x = z = (20 - y) / 2;
            if (y & 1)z++;
            cout << '|' << setw(x) << ' ' << item.medicineName << setw(z) << ' ' << '|';
            y = static_cast<int> (item.medicineNumber.size());
            x = z = (10 - y) / 2;
            if (y & 1)z++;
            cout << setw(x) << ' ' << item.medicineNumber << setw(z) << ' ' << '|';
            y = static_cast<int> (item.medicinePerPrice.size());
            x = z = (9 - y) / 2;
            if (y & 1)z++;
            cout << setw(x) << ' ' << item.medicinePerPrice << setw(z) << ' ' << '|';
            y = static_cast<int> (item.medicineTotalNum.size());
            x = z = (10 - y) / 2;
            if (y & 1)z++;
            cout << setw(x) << ' ' << item.medicineTotalNum << setw(z) << ' ' << '|';
            y = static_cast<int> (setPrecision(item.medicineTotalPrice).size());
            x = z = (10 - y) / 2;
            if (y & 1)z++;
            cout << setw(x) << ' ' << setPrecision(item.medicineTotalPrice) << setw(z) << ' ' << '|';
            y = static_cast<int> (item.medicineTradeDate.size());
            x = z = (14 - y) / 2;
            if (y & 1)z++;
            cout << setw(x) << ' ' << item.medicineTradeDate << setw(z) << ' ' << '|';
            y = static_cast<int> (item.medicineTradePerson.size());
            x = z = (14 - y) / 2;
            if (y & 1)z++;
            cout << setw(x) << ' ' << item.medicineTradePerson << setw(z) << ' ' << '|';
            y = static_cast<int> (item.medicineTradeType.size());
            x = z = (10 - y) / 2;
            if (y & 1)z++;
            cout << setw(x) << ' ' << item.medicineTradeType << setw(z) << ' ' << '|' << endl;
            for (int i = 0; i < 97; ++i)cout << '-';
            cout << endl;
        }

    }

    // Func.7 Check
    bool queryManagement()
    {
        cout << "========= 查询管理 =========" << endl << endl;
        L0:
        cout << "请输入您想要查询的信息类型（1/2），如果想退出请输入\'q\'" << endl;
        cout << "      1* 药品基本信息" << endl;
        cout << "      2* 药品交易信息" << endl;
        char ops;
        cin >> ops;
        switch (ops)
        {
            case '1':
            {
                // Case.1 check the basic information
                // Users can use Name, Species, Manufacture, Indate to check medicine
                cout << "请输入想要查询药品的基本信息（如果期望中不包含此项请输入\"-1\"，如果想退出请输入\'q\'）：" << endl;
                unordered_map<string, bool> medicineMap;
                cout << "药品名称：";
                string medicineName;
                cin >> medicineName;
                medicineMap[medicineName] = true;
                if (medicineName == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineName == "-1")
                {
                    medicineMap[medicineName] = false;
                }
                cout << "药品种类：";
                string medicineSpecies;
                cin >> medicineSpecies;
                medicineMap[medicineSpecies] = true;
                if (medicineSpecies == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineSpecies == "-1")
                {
                    medicineMap[medicineSpecies] = false;
                }
                cout << "生产厂家：";
                string medicineManufacture;
                cin >> medicineManufacture;
                medicineMap[medicineManufacture] = true;
                if (medicineManufacture == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineManufacture == "-1")
                {
                    medicineMap[medicineManufacture] = false;
                }
                cout << "有效日期：";
                string medicineIndate;
                cin >> medicineIndate;
                medicineMap[medicineIndate] = true;
                if (medicineIndate == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineIndate == "-1")
                {
                    medicineMap[medicineIndate] = false;
                }
                cout << endl;
                progressBar();
                if (!medicineMap[medicineName] && !medicineMap[medicineSpecies] && !medicineMap[medicineManufacture] &&
                    !medicineMap[medicineIndate])
                {
                    cout << "输入有误，请检查输入" << endl;
                    sleep(1);
                    goto L0;
                }
                // Output search result
                bool flag = true;
                cout << "%%%%%%%%% 查询结果 %%%%%%%%%" << endl << endl;
                for (auto &item: ioMedicineList)
                {
                    // Only two conditions the program will output result
                    // Case.1 We input a key && have a key = inputKey
                    // Case.2 We do not input a key (-1)
                    if (((medicineMap[medicineName] && item.name == medicineName) || !medicineMap[medicineName]) &&
                        ((medicineMap[medicineSpecies] && item.species == medicineSpecies) ||
                         !medicineMap[medicineSpecies]) &&
                        ((medicineMap[medicineManufacture] && item.manufacture == medicineManufacture) ||
                         !medicineMap[medicineManufacture]) &&
                        ((medicineMap[medicineIndate] && item.indate == medicineIndate) ||
                         !medicineMap[medicineIndate]))
                    {
                        cout << "药品编号：  " << item.number << endl;
                        cout << "药品名称：  " << item.name << endl;
                        cout << "药品种类：  " << item.species << endl;
                        cout << "生产厂家：  " << item.manufacture << endl;
                        cout << "药品价格：  " << item.price << endl;
                        cout << "有效日期：  " << item.indate << endl;
                        cout << "药品库存：  " << item.stock << endl;
                        cout << endl;
                        flag = false;
                    } else
                    {
                        continue;
                    }
                }
                if (flag)
                {
                    cout << "未查询到相关药品基本信息" << endl;
                    sleep(1);
                    goto L0;
                }
                break;
            }
            case '2':
            {
                // Case.2 check the trade information
                // Users can use Name, Date, Type to check medicine
                cout << "请输入想要查询药品的交易信息（如果期望中不包含此项请输入\"-1\"，如果想退出请输入\'q\'）：" << endl;
                cout << "药品名称：";
                unordered_map<string, bool> medicineMap;
                string medicineName;
                cin >> medicineName;
                medicineMap[medicineName] = true;
                if (medicineName == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineName == "-1")
                {
                    medicineMap[medicineName] = false;
                }
                cout << "交易日期：";
                string medicineTradeDate;
                cin >> medicineTradeDate;
                medicineMap[medicineTradeDate] = true;
                if (medicineTradeDate == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineTradeDate == "-1")
                {
                    medicineMap[medicineTradeDate] = false;
                }
                cout << "交易类型：";
                string medicineTradeType;
                cin >> medicineTradeType;
                medicineMap[medicineTradeType] = true;
                if (medicineTradeType == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineTradeType == "-1")
                {
                    medicineMap[medicineTradeType] = false;
                }
                cout << endl;
                progressBar();
                if (!medicineMap[medicineName] && !medicineMap[medicineTradeDate] && !medicineMap[medicineTradeType])
                {
                    cout << "输入有误，请检查输入" << endl;
                    sleep(1);
                    goto L0;
                }

                // TODO:逻辑匹配 Logic Match!!!
                readDealFile(); // medicineTradeList
                bool flag = true;
                cout << "%%%%%%%%% 查询结果 %%%%%%%%%" << endl << endl;
                cout.setf(ios::left);
                int x, y, z;
                for (int i = 0; i < 97; ++i)cout << '-';
                cout << endl;
                string title = "---------- 药品交易信息 ----------";
                y = static_cast<int> (title.size());
                x = z = (103 - y) / 2;
                if (y & 1)z++;
                cout << '|' << setw(x) << ' ' << title << setw(z + 1) << ' ' << '|';
                cout << endl;
                for (int i = 0; i < 97; ++i)cout << '-';
                cout << endl;
                cout << '|' << setw(3) << ' ' << "药品名称" << setw(4) << ' ' << '|';
                cout << setw(1) << ' ' << "药品编号" << setw(2) << ' ' << '|';
                cout << setw(1) << ' ' << "交易单价" << setw(2) << ' ' << '|';
                cout << setw(1) << ' ' << "交易数量" << setw(2) << ' ' << '|';
                cout << setw(1) << ' ' << "交易金额" << setw(2) << ' ' << '|';
                cout << setw(3) << ' ' << "交易时间" << setw(3) << ' ' << '|';
                cout << setw(3) << ' ' << "交易人员" << setw(3) << ' ' << '|';
                cout << setw(2) << ' ' << "交易方式" << setw(2) << ' ' << '|' << endl;
                for (int i = 0; i < 97; ++i)cout << '-';
                cout << endl;
                for (auto &item: medicineTradeList)
                {
                    if (((medicineMap[medicineName] && item.medicineName == medicineName) ||
                         !medicineMap[medicineName]) &&
                        ((medicineMap[medicineTradeDate] && item.medicineTradeDate == medicineTradeDate) ||
                         !medicineMap[medicineTradeDate]) &&
                        ((medicineMap[medicineTradeType] && item.medicineTradeType == medicineTradeType) ||
                         !medicineMap[medicineTradeType]))
                    {
                        y = static_cast<int> (item.medicineName.size());
                        x = z = (20 - y) / 2;
                        if (y & 1)z++;
                        cout << '|' << setw(x) << ' ' << item.medicineName << setw(z) << ' ' << '|';
                        y = static_cast<int> (item.medicineNumber.size());
                        x = z = (10 - y) / 2;
                        if (y & 1)z++;
                        cout << setw(x) << ' ' << item.medicineNumber << setw(z) << ' ' << '|';
                        y = static_cast<int> (item.medicinePerPrice.size());
                        x = z = (9 - y) / 2;
                        if (y & 1)z++;
                        cout << setw(x) << ' ' << item.medicinePerPrice << setw(z) << ' ' << '|';
                        y = static_cast<int> (item.medicineTotalNum.size());
                        x = z = (10 - y) / 2;
                        if (y & 1)z++;
                        cout << setw(x) << ' ' << item.medicineTotalNum << setw(z) << ' ' << '|';
                        y = static_cast<int> (setPrecision(item.medicineTotalPrice).size());
                        x = z = (10 - y) / 2;
                        if (y & 1)z++;
                        cout << setw(x) << ' ' << setPrecision(item.medicineTotalPrice) << setw(z) << ' ' << '|';
                        y = static_cast<int> (item.medicineTradeDate.size());
                        x = z = (14 - y) / 2;
                        if (y & 1)z++;
                        cout << setw(x) << ' ' << item.medicineTradeDate << setw(z) << ' ' << '|';
                        y = static_cast<int> (item.medicineTradePerson.size());
                        x = z = (14 - y) / 2;
                        if (y & 1)z++;
                        cout << setw(x) << ' ' << item.medicineTradePerson << setw(z) << ' ' << '|';
                        y = static_cast<int> (item.medicineTradeType.size());
                        x = z = (10 - y) / 2;
                        if (y & 1)z++;
                        cout << setw(x) << ' ' << item.medicineTradeType << setw(z) << ' ' << '|' << endl;
                        for (int i = 0; i < 97; ++i)cout << '-';
                        cout << endl;
                        flag = false;
                    } else
                    {
                        continue;
                    }
                }
                if (flag)
                {
                    cout << "未查询到相关药品操作信息" << endl;
                    sleep(1);
                    goto L0;
                }
                break;

            }
            case 'q':
            {
                cout << "查询管理结束" << endl;
                return false;
            }
            default:
                break;
        }

        return true;
    }

    // Func.8
    bool statisticalManagement()
    {
        cout << "========= 统计管理 =========" << endl << endl;
        L0:
        cout << "请输入您想要查询的信息类型（1/2），如果想退出请输入\'q\'" << endl;
        cout << "      1* 药品基本信息" << endl;
        cout << "      2* 药品交易信息" << endl;
        char ops;
        cin >> ops;
        switch (ops)
        {
            case '1':
            {
                // Count medicine basic information
                // medicineName, medicineSpecies, Manufacture and Indate can be used to find the Stock
                cout << "请输入想要查询药品的基本信息（如果期望中不包含此项请输入\"-1\"，如果想退出请输入\'q\'）：" << endl;
                unordered_map<string, bool> medicineMap;
                cout << "药品名称：";
                string medicineName;
                cin >> medicineName;
                medicineMap[medicineName] = true;
                if (medicineName == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineName == "-1")
                {
                    medicineMap[medicineName] = false;
                }
                cout << "药品种类：";
                string medicineSpecies;
                cin >> medicineSpecies;
                medicineMap[medicineSpecies] = true;
                if (medicineSpecies == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineSpecies == "-1")
                {
                    medicineMap[medicineSpecies] = false;
                }
                cout << "生产厂家：";
                string medicineManufacture;
                cin >> medicineManufacture;
                medicineMap[medicineManufacture] = true;
                if (medicineManufacture == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineManufacture == "-1")
                {
                    medicineMap[medicineManufacture] = false;
                }
                cout << "有效日期：";
                string medicineIndate;
                cin >> medicineIndate;
                medicineMap[medicineIndate] = true;
                if (medicineIndate == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineIndate == "-1")
                {
                    medicineMap[medicineIndate] = false;
                }
                cout << endl;
                progressBar();
                if (!medicineMap[medicineName] && !medicineMap[medicineSpecies] && !medicineMap[medicineManufacture] &&
                    !medicineMap[medicineIndate])
                {
                    cout << "输入有误，请检查输入" << endl;
                    sleep(1);
                    goto L0;
                }
                // Output search result
                bool flag = true;
                int medicineStock = 0;
                cout << "%%%%%%%%% 查询结果 %%%%%%%%%" << endl << endl;
                for (auto &item: ioMedicineList)
                {
                    // Only two conditions the program will output result
                    // Case.1 We input a key && have a key = inputKey
                    // Case.2 We do not input a key (-1)
                    if (((medicineMap[medicineName] && item.name == medicineName) || !medicineMap[medicineName]) &&
                        ((medicineMap[medicineSpecies] && item.species == medicineSpecies) ||
                         !medicineMap[medicineSpecies]) &&
                        ((medicineMap[medicineManufacture] && item.manufacture == medicineManufacture) ||
                         !medicineMap[medicineManufacture]) &&
                        ((medicineMap[medicineIndate] && item.indate == medicineIndate) ||
                         !medicineMap[medicineIndate]))
                    {
                        medicineStock += stoi(item.stock);
                        flag = false;
                    } else
                    {
                        continue;
                    }
                }
                if (flag)
                {
                    cout << "未查询到相关药品基本信息" << endl;
                    sleep(1);
                    goto L0;
                } else
                {
                    cout << "满足条件药品的库存为：    " << medicineStock << endl;
                }
                break;
            }
            case '2':
            {
                // Count medicine trade information
                // medicineName, TradeDate and TradeType can be used to find TradeNum and TradePrice
                cout << "请输入想要查询药品的交易信息（如果期望中不包含此项请输入\"-1\"，如果想退出请输入\'q\'）：" << endl;
                cout << "药品名称：";
                unordered_map<string, bool> medicineMap;
                string medicineName;
                cin >> medicineName;
                medicineMap[medicineName] = true;
                if (medicineName == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineName == "-1")
                {
                    medicineMap[medicineName] = false;
                }
                cout << "交易日期：";
                string medicineTradeDate;
                cin >> medicineTradeDate;
                medicineMap[medicineTradeDate] = true;
                if (medicineTradeDate == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineTradeDate == "-1")
                {
                    medicineMap[medicineTradeDate] = false;
                }
                cout << "交易类型：";
                string medicineTradeType;
                cin >> medicineTradeType;
                medicineMap[medicineTradeType] = true;
                if (medicineTradeType == "q")
                {
                    cout << "* 正在退出" << endl;
                    sleep(1);
                    goto L0;
                } else if (medicineTradeType == "-1")
                {
                    medicineMap[medicineTradeType] = false;
                }
                cout << endl;
                progressBar();
                if (!medicineMap[medicineName] && !medicineMap[medicineTradeDate] && !medicineMap[medicineTradeType])
                {
                    cout << "输入有误，请检查输入" << endl;
                    sleep(1);
                    goto L0;
                }

                // TODO:逻辑匹配 Logic Match!!!
                readDealFile(); // medicineTradeList
                bool flag = true;
                int inStorageNum = 0;
                int outStockNum = 0;
                double inStoragePrice = 0;
                double outStockPrice = 0;
                cout << "%%%%%%%%% 查询结果 %%%%%%%%%" << endl << endl;
                for (auto &item: medicineTradeList)
                {
                    if (((medicineMap[medicineName] && item.medicineName == medicineName) ||
                         !medicineMap[medicineName]) &&
                        ((medicineMap[medicineTradeDate] && item.medicineTradeDate == medicineTradeDate) ||
                         !medicineMap[medicineTradeDate]) &&
                        ((medicineMap[medicineTradeType] && item.medicineTradeType == medicineTradeType) ||
                         !medicineMap[medicineTradeType]))
                    {
                        if (item.medicineTradeType == "采购")
                        {
                            inStorageNum += stoi(item.medicineTotalNum);
                            inStoragePrice += stod(item.medicineTotalPrice);
                        } else if (item.medicineTradeType == "销售")
                        {
                            outStockNum += stoi(item.medicineTotalNum);
                            outStockPrice += stod(item.medicineTotalPrice);
                        }
                        flag = false;
                    } else
                    {
                        continue;
                    }
                }
                if (flag)
                {
                    cout << "未查询到相关药品操作信息" << endl;
                    sleep(1);
                    goto L0;
                } else
                {
                    cout << fixed << showpoint;
                    cout << setprecision(3);
                    cout << "采购数量：  " << inStorageNum << endl;
                    cout << "销售数量：  " << outStockNum << endl;
                    cout << "采购金额：  " << inStoragePrice << endl;
                    cout << "销售金额：  " << outStockPrice << endl;
                }
                break;

            }
            case 'q':
            {
                cout << "查询管理结束" << endl;
                return false;
            }
            default:
                break;
        }

        return true;
    }

    // Convert yyyy/mm/dd to yyyy/mm
    static string Convert(string &str)
    {
        string year, month;
        int i = 0;
        for (char &ch: str)
        {
            if (!isdigit(ch))
            {
                ch = ' ';
            }
        }
        stringstream ss(str);
        ss >> year;
        ss >> month;
        return (year + "/" + month);
    }


    // Func.9
    bool reportSummary()
    {
        // map<year/month, map<medicineNum, tradeMember>>
        map<string, map<string, vector<tradeMember>>, greater<string>> medicineMap;
        vector<medicineMessage> medVtr;
        cout << "---------- 汇总报表 ----------" << endl;
        L0:
        cout << "请输入想要汇总的药品信息编号（如果想退出请输入\'q\'）：" << endl;
        cout << "    *1 药品名称" << endl;
        cout << "    *2 药品种类" << endl;
        cout << "    *3 生产厂家" << endl;
        char ops;
        cin >> ops;
        string medicineName;
        string medicineSpecies;
        string medicineManufacture;
        switch (ops)
        {
            case 'q':
            {
                cout << "* 正在退出" << endl;
                sleep(1);
                return false;
            }
            case '1':
            {
                cout << "请输入药品名称：";
                cin >> medicineName;
                break;
            }
            case '2':
            {
                cout << "请输入药品种类：";
                cin >> medicineSpecies;
                break;
            }
            case '3':
            {
                cout << "请输入生产厂家：";
                cin >> medicineManufacture;
                break;
            }
            default:
                break;
        }
        for (auto &item: ioMedicineList)
        {
            if (ops == '1')
            {
                if (item.name == medicineName)
                {
                    medVtr.push_back(item);
                }
            } else if (ops == '2')
            {
                if (item.species == medicineSpecies)
                {
                    medVtr.push_back(item);
                }
            } else if (ops == '3')
            {
                if (item.manufacture == medicineManufacture)
                {
                    medVtr.push_back(item);
                }
            }
        }

        readDealFile(); // medicineTradeList
        for (auto &item: medVtr)
        {
            for (auto itr: medicineTradeList)
            {
                if (item.number == itr.medicineNumber)
                {
                    medicineMap[Convert(itr.medicineTradeDate)][itr.medicineNumber].push_back(itr);
                }
            }
        }
        if (medVtr.empty())
        {
            cout << "No" << '\n';
        }

        if (medicineMap.empty())
        {
            cout << "未找到符合条件的药品，请检查输入" << endl;
            goto L0;
        }

        cout << "%%%%%%%%%%%%%%%%%%% 查 询 结 果 %%%%%%%%%%%%%%%%%%%" << endl << endl;

        for (auto &itr1: medicineMap)
        {

            cout << endl;
            for (int i = 0; i <= 41; ++i)
            {
                cout << ' ';
            }
            cout << left << setw(10) << itr1.first;
            for (int i = 0; i <= 41; ++i)
            {
                cout << ' ';
            }
            cout << endl;

            for (int i = 0; i < 110; ++i)
            {
                cout << '-';
            }
            cout << endl;
            for (int i = 0; i <= 40; ++i)
            {
                cout << ' ';
            }
            cout << left << setw(12) << "药品基本信息";
            for (int i = 0; i <= 40; ++i)
            {
                cout << ' ';
            }
            cout << endl;

            for (int i = 0; i < 110; ++i)
            {
                cout << '-';
            }
            cout << endl;
            cout << " 药品编号 " << '|';
            cout << "   药品名称   " << '|';
            cout << "      药品种类      " << '|';
            cout << "      生产厂家      " << '|';
            cout << " 药品价格 " << '|';
            cout << "  有效日期  " << '|';
            cout << "  注意事项  " << '|';
            cout << " 药品库存 ";
            cout << endl;

            for (auto &itr2: itr1.second)
            {
                medicineMessage msg;
                for (auto &tmp: ioMedicineList)
                {
                    if (tmp.number == itr2.first)
                    {
                        msg = tmp;
                    }
                }
                for (int i = 0; i < 110; ++i)
                {
                    cout << '-';
                }
                cout << endl;
                cout << "  " << msg.number << " " << '|';
                cout << " " << msg.name << " " << '|';
                cout << " " << msg.species << " " << '|';
                cout << " " << msg.manufacture << " " << '|';
                cout << " " << msg.price << " " << '|';
                cout << " " << msg.indate << " " << '|';
                cout << " " << msg.attentionMatters << " " << '|';
                cout << " " << msg.stock;
                cout << endl;

                for (int i = 0; i < 110; ++i)
                {
                    cout << '-';
                }
                cout << endl;
                sort(itr2.second.begin(), itr2.second.end(), dateCompare);


                cout << endl;
                for (int i = 0; i <= 40; ++i)
                {
                    cout << ' ';
                }
                cout << left << setw(12) << "药品交易信息";
                for (int i = 0; i <= 40; ++i)
                {
                    cout << ' ';
                }
                cout << endl;
                for (int i = 0; i < 110; ++i)
                {
                    cout << '-';
                }
                cout << endl;
                cout << "     交易数量     " << '|';
                cout << "          交易金额           " << '|';
                cout << "         交易时间         " << '|';
                cout << "        交易方式        ";
                cout << endl;
                for (int i = 0; i < 110; ++i)
                {
                    cout << '-';
                }
                cout << endl;

                int totalSales = 0;
                for (auto &itr3: itr2.second)
                {
                    cout << "        " << itr3.medicineTotalNum << "         " << '|';
                    cout << "         " << setPrecision(itr3.medicineTotalPrice) << "         " << '|';
                    cout << "         " << itr3.medicineTradeDate << "         " << '|';
                    cout << "         " << itr3.medicineTradeType;
                    cout << endl;
                    for (int i = 0; i < 110; ++i)
                    {
                        cout << '-';
                    }
                    cout << endl;
                    if (itr3.medicineTradeType == "销售")
                    {
                        totalSales += stoi(itr3.medicineTotalNum);
                    }
                }

                cout << "   " << "月销量：   ";
                cout << totalSales;
                cout << " （件）";
                cout << endl;
                for (int i = 0; i < 110; ++i)
                {
                    cout << '-';
                }
                cout << endl;

            }

            cout << endl;
        }

        return true;
    }

private:
    struct tradeMember
    {
        string medicineName;
        string medicineNumber;
        string medicinePerPrice;
        string medicineTotalNum;
        string medicineTotalPrice;
        string medicineTradeDate;
        string medicineTradePerson;
        string medicineTradeType;
    };
    list<tradeMember> medicineTradeList;

    // Compare function
    static bool dateCompare(const tradeMember &trM1, const tradeMember &trM2)
    {
        // Descending sort
        return (trM1.medicineTradeDate > trM2.medicineTradeDate);
    }

public:
    void readDealFile()
    {
        ifstream ifstr(fileDealPath, ios::in);
        char ch[200];
        tradeMember tMem;

        medicineTradeList.clear();
        ifstr.getline(ch, sizeof(ch));
        while (!ifstr.eof())
        {
            ifstr.getline(ch, sizeof(ch));
            tMem.medicineName = ch;
            ifstr.getline(ch, sizeof(ch));
            tMem.medicineNumber = ch;
            ifstr.getline(ch, sizeof(ch));
            tMem.medicinePerPrice = ch;
            ifstr.getline(ch, sizeof(ch));
            tMem.medicineTotalNum = ch;
            ifstr.getline(ch, sizeof(ch));
            tMem.medicineTotalPrice = ch;
            ifstr.getline(ch, sizeof(ch));
            tMem.medicineTradeDate = ch;
            ifstr.getline(ch, sizeof(ch));
            tMem.medicineTradePerson = ch;
            ifstr.getline(ch, sizeof(ch));
            tMem.medicineTradeType = ch;

            medicineTradeList.push_back(tMem);
        }

        ifstr.close();
    }
};

// Set and reset the password
string password;
bool pwd = false;
bool flag = true;
const string root = "20105050110"; /* NOLINT */
void login()
{
    if (!pwd)
    {
        // The password is not set
        cout << "请为系统设置密码：";
        cin >> password;
        pwd = true;
    } else
    {
        // The password has been set
        cout << endl
             << "##### 按「l」以输入密码登录系统 ##### 按「r」以重设密码 #####" << endl;
        char ch;
        getchar();      // Get the top '\n'
        ch = getchar(); /* NOLINT */
        getchar();      // Get the input '\n'
        switch (ch)
        {
            case 'l':
            {
                L1:
                cout << "请输入密码：";
                string tmp;
                cin >> tmp;
                if (tmp == password)
                {
                    cout << endl;
                    progressBar();
                    cout << endl;
                    sleep(1);
                    cout << endl;
                    cout << "@@@@@@@@ 欢 迎 使 用 @@@@@@@@" << endl
                         << endl;
                    flag = false;
                    sleep(1);
                    system("clear");
                    // On Windows
                    // system("cls");
                } else
                {
                    sleep(1);
                    cout << "您输入的密码不匹配，请重新输入！" << endl
                         << endl;
                    goto L1;
                }
                break;
            }
            case 'r':
            {
                L2:
                cout << "请输入root密码：";
                string tmp;
                cin >> tmp;
                if (tmp == root)
                {
                    sleep(1);
                    cout << "========== Admin ==========" << endl;
                    sleep(1);
                    cout << "尊敬的管理员欢迎您！" << endl;
                    sleep(1);
                    cout << "请输入您想重设的密码：" << endl;
                    cin >> password;
                    pwd = true;
                    flag = false;
                    progressBar();
                    sleep(1);
                    cout << endl
                         << "密码已经重新设置！" << endl
                         << endl;
                    system("clear");
                    // On Windows
                    // system("cls");
                } else
                {
                    cout << "密码错误！若想重设密码请联系管理员" << endl;
                    goto L2;
                }
                break;
            }

            default:
                break;
        }
    }
}

// Hint print
void Hint()
{
    time_t now = time(nullptr);
    string dt = ctime(&now);

    cout << "========== 药品供销管理系统 ==========" << endl
         << endl;
    cout << "     -----    欢迎使用！   -----    " << endl;
    cout << "      " << dt << endl
         << endl;
    cout << "     * 1: 设置及修改密码" << endl;
    cout << "     * 2: 录入药品基本信息" << endl;
    cout << "     * 3: 药品入库管理" << endl;
    cout << "     * 4: 药品销售管理" << endl;
    cout << "     * 5: 修改药品基本信息" << endl;
    cout << "     * 6: 输出全部药品信息" << endl;
    cout << "     * 7: 查询管理" << endl;
    cout << "     * 8: 统计管理" << endl;
    cout << "     * 9: 汇总报表" << endl;
    cout << "     * q: 退出系统" << endl
         << endl;
    cout << "ps. 所有功能在执行完毕后，都会自动将当前信息保存进文件" << endl
         << endl;
}

int main()
{

    // Clarify a Medicine Class
    Medicine medicine; /* NOLINT */

    Hint();

    if (!pwd)
    {
        cout << "请先选1设置密码：";
        char ch;
        ch = getchar(); /* NOLINT */
        getchar();      /* NOLINT */
        while (ch != '1')
        {
            cout << "请先选1设置密码！";
            ch = getchar(); /* NOLINT */
            getchar();
        }
        while (flag)
        {
            login();
        }
    } else
    {
        cout << "请先选1登录系统：";
        char ch;
        ch = getchar(); /* NOLINT */
        getchar();
        while (ch != '1')
        {
            cout << "请先选1登录系统！";
            ch = getchar(); /* NOLINT */
            getchar();
        }
        while (flag)
        {
            login();
        }
    }
    if (!flag)
    {
        while (true)
        {
            Hint();
            cout << "请输入您的需求：";
            char ch;
            ch = getchar(); /* NOLINT */
            ch = getchar(); /* NOLINT */
            switch (ch)
            {
                case '1':
                {
                    flag = true;
                    L3:
                    cout << "请输入root密码：";
                    string tmp;
                    cin >> tmp;
                    if (tmp == root)
                    {
                        sleep(1);
                        cout << "========== Admin ==========" << endl;
                        sleep(1);
                        cout << "尊敬的管理员欢迎您！" << endl;
                        sleep(1);
                        cout << "请输入您想重设的密码：" << endl;
                        cin >> password;
                        pwd = true;
                        flag = false;
                        cout << endl;
                        progressBar();
                        sleep(1);
                        cout << endl
                             << "密码已经重新设置！" << endl
                             << endl;

                        system("clear");
                        // On Windows
                        // system("cls");
                    } else
                    {
                        cout << "root密码错误，若想重设密码请联系管理员" << endl;
                        goto L3;
                    }
                    break;
                }
                case '2':
                {
                    while (medicine.logMedicineMessage());
                    cout << "药品信息录入完成" << endl;
                    sleep(1);
                    cout << "谢谢使用！" << endl;
                    sleep(1);
                    system("clear");
                    // On Windows
                    // system("cls");
                    break;
                }
                case '3':
                {
                    while (medicine.intoStorageMedicine());
                    cout << "药品入库完成" << endl;
                    sleep(1);
                    cout << "谢谢使用！" << endl;
                    sleep(1);
                    system("clear");
                    // On Windows
                    // system("cls");
                    break;
                }
                case '4':
                {
                    while (medicine.outStockMedicine());
                    cout << "药品出库完成" << endl;
                    sleep(1);
                    cout << "谢谢使用！" << endl;
                    sleep(1);
                    system("clear");
                    // On Windows
                    // system("cls");
                    break;
                }
                case '5':
                {
                    while (medicine.modify());
                    system("clear");
                    // On Windows
                    // system("cls");
                    break;
                }
                case '6':
                {
                    medicine.outputAllMessages();
                    sleep(3);
                    cout << endl
                         << "输入\'q\'继续" << endl;
                    char q;
                    L4:
                    cin.get(q);
                    if (q == 'q')
                    {
                        break;
                    } else
                    {
                        goto L4;
                    }
                }
                case '7':
                {
                    while (medicine.queryManagement());
                    cout << "谢谢使用" << endl;
                    sleep(1);
                    system("clear");
                    // On Windows
                    // system("cls");
                    break;
                }
                case '8':
                {
                    while (medicine.statisticalManagement());
                    cout << "谢谢使用" << endl;
                    sleep(1);
                    system("clear");
                    // On Windows
                    // system("cls");
                    break;
                }
                case '9':
                {
                    while (medicine.reportSummary());
                    cout << "谢谢使用" << endl;
                    sleep(1);
                    system("clear");
                    // On Windows
                    // system("cls");
                    break;
                }
                case 'q':
                {
                    cout << endl
                         << "感谢您的使用，再会👋" << endl
                         << endl;
                    cout << "============== E O F ==============" << endl;
                    return 0;
                }
                default:
                    break;
            }
        }
    }

    return 0;
}
