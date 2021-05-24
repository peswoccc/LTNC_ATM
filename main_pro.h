void one_so_du(tai_khoan &tk)
{
    cout << text[33][language] << tk.id_money << " VND." << endl;
}

void two_nap_tien(tai_khoan &tk)
{
    cout << text[34][language];
    int a[7];
    string menh_gia[] = {"", "10000 VND", "20000 VND", "50000 VND", "100000 VND", "200000 VND", "500000 VND"};
    int int_menh_gia[] = {0, 10000, 20000, 50000, 100000, 200000, 500000};
    file_to_money(a[1], a[2], a[3], a[4], a[5], a[6]);
    int x, soto;
    cin >> x;
    cout << text[25][language] << menh_gia[x] << text[35][language];
    cin >> soto;
    a[x]+= soto;
    tk.id_money += soto * int_menh_gia[x];
    int add_money = soto * int_menh_gia[x];
    cout << text[36][language];
    int lai;
    cin >> lai;
    while (lai == 1)
    {
        system("cls");
        cout << text[34][language];
        cin >> x;
        cout << text[25][language] << menh_gia[x] << text[35][language];
        cin >> soto;
        a[x]+= soto;
        tk.id_money += soto * int_menh_gia[x];
        cout << text[36][language];
        cin >> lai;
        add_money += soto * int_menh_gia[x];

    }
    save_tk(tk);
    system("cls");
    money_to_file(a[1], a[2], a[3], a[4], a[5], a[6]);

    //tieng viet
    stringstream ss;
    ss << setw(21) << left << tk.id << " +" << setw(21) << left << to_string(add_money) + " VND" << setw(40) << left << "nap tien tai ATM" << date_time_now();
    add_history1(ss);

    //tieng anh
    stringstream ss2;
    ss2 << setw(21) << left << tk.id << " +" << setw(21) << left << to_string(add_money) + " VND" << setw(40) << left << "adding money at ATM" << date_time_now();
    add_history2(ss2);
}

void three_rut_tien_pick(int &k10, int &k20, int &k50, int &k100, int &k200, int &k500, int tien_rut)
{
    k500 = tien_rut/500000;
    tien_rut = tien_rut%500000;
    k200 = tien_rut/200000;
    tien_rut = tien_rut%200000;
    k100 = tien_rut/100000;
    tien_rut = tien_rut%100000;
    k50 = tien_rut/50000;
    tien_rut = tien_rut%50000;
    k20 = tien_rut/20000;
    tien_rut = tien_rut%20000;
    k10 = tien_rut/10000;
    tien_rut = tien_rut%10000;
}

void three_rut_tien(tai_khoan &tk)
{
    int x;
    cout << text[33][language] << tk.id_money << " VND\n\n";
    cout << text[37][language];
    cin >> x;
    while (x > tk.id_money || x < 10000 || x > 5000000 || x % 10000 != 0)
    {
        system("cls");
        cout << text[33][language] << tk.id_money << " VND\n\n";
        cout << text[38][language];
        cout << text[39][language];
        cin >> x;
    }
    int r10, r20, r50, r100, r200, r500;
    three_rut_tien_pick(r10, r20, r50, r100, r200, r500, x);
    int k10, k20, k50, k100, k200, k500;
    file_to_money(k10, k20, k50, k100, k200, k500);
    if (k10 < r10 || k20 < r20 || k50 < r50 || k100 < r100 || k200 < r200 || k500 < r500)
    {
        system("cls");
        cout << text[63][language];
        getch();
        system("cls");
    }
    else
    {
        system("cls");
        cout << text[40][language] << x <<" VND\n\n";
        cout << text[41][language];
        cout << setw(20) <<  left << text[21][language] << text[22][1] << endl;
        if (r10 != 0) cout << setw(20) <<  left << "10000" << r10 << endl;
        if (r20 != 0) cout << setw(20) <<  left << "20000" << r20 << endl;
        if (r50 != 0) cout << setw(20) <<  left << "50000" << r50 << endl;
        if (r100 != 0) cout << setw(20) <<  left << "100000" << r100 << endl;
        if (r200 != 0) cout << setw(20) <<  left << "200000" << r200 << endl;
        if (r500 != 0) cout << setw(20) <<  left << "500000" << r500 << endl;
        tk.id_money -= x;
        save_tk(tk);
        money_to_file(k10-r10, k20-r20, k50-r50, k100-r100, k200-r200, k500-r500);

        //tieng viet
        stringstream ss;
        ss << setw(21) << left << tk.id << " -" << setw(21) << left << to_string(x) + " VND" << setw(40) << left << "rut tien tai ATM" << date_time_now();
        add_history1(ss);

        //tieng anh
        stringstream ss2;
        ss2 << setw(21) << left << tk.id << " -" << setw(21) << left << to_string(x) + " VND" << setw(40) << left << "withdraw money at ATM" << date_time_now();
        add_history2(ss2);

    }
}

void four_chuyen_tien(tai_khoan &tk)
{
    vector<tai_khoan> v4 = file_to_tk();
    int n4 = v4.size();
    cout << text[42][language];
    string new_id;
    cin >> new_id;
    while(tk.id == new_id || !id_exist(new_id, v4))
    {
        system("cls");
        if (tk.id == new_id)
            cout << text[43][language];
        else
            cout << text[44][language];
        cin >> new_id;
    }
    system("cls");
    cout << text[45][language] << new_id << "\n";
    cout << text[33][language] << tk.id_money << " VND\n";
    cout << text[46][language];
    int add_money;
    cin >> add_money;
    while(add_money > tk.id_money)
    {
        system("cls");
        cout << text[45][language] << new_id << "\n";
        cout << text[33][language] << tk.id_money << " VND\n";
        cout << text[46][language];
        cin >> add_money;
    }
    for (int i = 0; i < n4; i++)
    {
        if (new_id == v4[i].id)
        {
            v4[i].id_money += add_money;
            break;
        }
    }
    for (int i = 0; i < n4; i++)
    {
        if (tk.id == v4[i].id)
        {
            v4[i].id_money -= add_money;
            break;
        }
    }
    tk_to_file(v4);
    tk.id_money -= add_money;
    system("cls");
    cout << text[47][language];

    //luu lich su tieng viet
    stringstream ss, sss;
    ss << setw(21) << left << tk.id << " -" << setw(21) << left << to_string(add_money) + " VND" << setw(40) << left <<  "chuyen tien toi " + new_id << date_time_now();
    add_history1(ss);
    sss << setw(21) << left << new_id << " +" << setw(21) << left << to_string(add_money) + " VND" << setw(40) << left << "nhan tien tu " + tk.id << date_time_now();
    add_history1(sss);

    //luu lich su tieng anh
    stringstream ss2, sss2;
    ss2 << setw(21) << left << tk.id << " -" << setw(21) << left << to_string(add_money) + " VND" << setw(40) << left <<  "send money to " + new_id << date_time_now();
    add_history2(ss2);
    sss2 << setw(21) << left << new_id << " +" << setw(21) << left << to_string(add_money) + " VND" << setw(40) << left << "receive money from " + tk.id << date_time_now();
    add_history2(sss2);
}

void five_history(tai_khoan &tk)
{
    cout << setw(22) << left << text[4][language] << setw(22) << left << text[28][language] << setw(40) << left << text[29][language] << text[30][language] << endl;
    ifstream fin;
    if (language == 1) fin.open("history1.txt");
    else fin.open("history2.txt");
    while(!fin.eof())
    {
        stringstream ss;
        string s, _id;
        getline(fin, s);
        ss << s;
        ss >> _id;
        if (_id == tk.id) cout << s << endl;
    }
    fin.close();
}

void six_delete_history(tai_khoan &tk)
{
    ifstream fin("history1.txt");
    ofstream fout("history_new.txt");
    while(!fin.eof())
    {
        stringstream ss;
        string s, _id;
        getline(fin, s);
        ss << s;
        ss >> _id;
        if (_id != tk.id) fout << s << endl;
    }
    fin.close();
    fout.close();
    remove("history1.txt");
    rename("history_new.txt", "history1.txt");

    fin.open("history2.txt");
    fout.open("history_new.txt");
    while(!fin.eof())
    {
        stringstream ss;
        string s, _id;
        getline(fin, s);
        ss << s;
        ss >> _id;
        if (_id != tk.id) fout << s << endl;
    }
    fin.close();
    fout.close();
    remove("history2.txt");
    rename("history_new.txt", "history2.txt");

    cout << text[31][language];
}

void seven_new_password(tai_khoan &tk)
{
    cout << setw(30) << left << text[48][language] << tk.id << endl;
    cout << setw(30) << left << text[49][language] << tk.pass << endl << endl;
    cout << text[50][language];
    string new_pass;
    cin >> new_pass;
    while(new_pass == tk.pass || !id_valid(new_pass))
    {
        system("cls");
        cout << setw(30) << left << text[48][language] << tk.id << endl;
        cout << setw(30) << left << text[49][language] << tk.pass << endl << endl;
        cout << text[51][language];
        cin >> new_pass;
    }
    tk.pass = new_pass;
    save_tk(tk);
    system("cls");
    cout << text[52][language];
}

void main_pro(tai_khoan &tk, vector<tai_khoan> &v)
{
    system("cls");
    cout << text[53][language] << tk.id << "\n" << text[54][language];
    string x;
    cin >> x;
    system("cls");
    while (x.size() != 1 || x[0] < '1' || x[0] > '8')
    {
        system("cls");
        cout << text[53][language] << tk.id << "\n" << text[54][language];
        cout << text[62][language];
        cin >> x;
    }
    if (x == "1")
    {
        one_so_du(tk);
        save_tk(tk);
        v = file_to_tk();
        again(main_pro(tk,v));
    }
    else if (x == "2")
    {
        two_nap_tien(tk);
        save_tk(tk);
        v = file_to_tk();
        again(main_pro(tk,v));
    }
    else if (x == "3")
    {
        three_rut_tien(tk);
        save_tk(tk);
        v = file_to_tk();
        again(main_pro(tk,v));
    }
    else if (x == "4")
    {
        four_chuyen_tien(tk);
        save_tk(tk);
        v = file_to_tk();
        again(main_pro(tk,v));
    }
    else if (x == "5")
    {
        five_history(tk);
        save_tk(tk);
        v = file_to_tk();
        again(main_pro(tk,v));
    }
    else if (x == "6")
    {
        six_delete_history(tk);
        save_tk(tk);
        v = file_to_tk();
        again(main_pro(tk,v));
    }
    else if (x == "7")
    {
        seven_new_password(tk);
        save_tk(tk);
        v = file_to_tk();
        again(main_pro(tk,v));
    }
}

