//#define again(a) {if (lam_lai()) a; else thanks();}
#define again(a) {if (lam_lai()) a;}

static int language;
static string text[100][5];

void choose_language()
{
    cout << "Please choose language: \n1 - Tieng Viet   2 - English\n";
    cin >> language;
    system("cls");
}

struct tai_khoan
{
    string id;
    string pass;
    int id_money;
    bool locked;
};

bool lam_lai()
{
    cout << text[1][language];
    int x1;
    cin >> x1;
    system("cls");
    if (x1 == 1) return 1;
    else return 0;
}

void thanks()
{
    system("cls");
    cout << text[2][language];
}

void add_history1(stringstream &ss)
{
    string s;
    getline(ss,s);
    ofstream fout("history1.txt", ios :: app);
    fout << s << endl;
    fout.close();
}

void add_history2(stringstream &ss)
{
    string s;
    getline(ss,s);
    ofstream fout("history2.txt", ios :: app);
    fout << s << endl;
    fout.close();
}

vector<tai_khoan> file_to_tk()
{
    ifstream f("tai_khoan.txt");
    int n;
    f >> n;
    vector<tai_khoan> ans;
    for (int i = 0; i < n; i++)
    {
        tai_khoan tam;
        f >> tam.id >> tam.pass >> tam.id_money >> tam.locked;
        ans.push_back(tam);
    }
    return ans;
}

void tk_to_file(vector <tai_khoan> &tk)
{
    int n = tk.size();
    ofstream f("tai_khoan.txt");
    f.clear();
    f << n << endl;
    for (int i = 0; i < n; i++)
        f << tk[i].id << " " << tk[i].pass << " " << tk[i].id_money << " " << tk[i].locked << endl;
}

void file_to_money(int &k10, int &k20, int &k50, int &k100, int &k200, int &k500)
{
    ifstream f("10000.txt");
    f >> k10;
    f.close();
    f.open("20000.txt");
    f >> k20;
    f.close();
    f.open("50000.txt");
    f >> k50;
    f.close();
    f.open("100000.txt");
    f >> k100;
    f.close();
    f.open("200000.txt");
    f >> k200;
    f.close();
    f.open("500000.txt");
    f >> k500;
    f.close();
}

void money_to_file(int k10, int k20, int k50, int k100, int k200, int k500)
{
    ofstream f("10000.txt");
    f << k10;
    f.close();
    f.open("20000.txt");
    f << k20;
    f.close();
    f.open("50000.txt");
    f << k50;
    f.close();
    f.open("100000.txt");
    f << k100;
    f.close();
    f.open("200000.txt");
    f << k200;
    f.close();
    f.open("500000.txt");
    f << k500;
    f.close();
}

void save_tk(tai_khoan &tk)
{
    vector<tai_khoan> v = file_to_tk();
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (tk.id == v[i].id)
        {
            v[i] = tk;
            break;
        }
    }
    tk_to_file(v);
}

string date_time_now()
{
	time_t now = time(0);
	tm *hien_tai = localtime(&now);
	stringstream ss;
	ss << setfill('0') << setw(2) << hien_tai->tm_mday << "/"
	<< setfill('0') << setw(2) << hien_tai->tm_mon + 1 << "/"
	<< hien_tai->tm_year + 1900 << " "
	<< setfill('0') << setw(2)<< hien_tai->tm_hour << ":"
	<< setfill('0') << setw(2)<< hien_tai->tm_min;
	string ans;
	getline(ss, ans);
	return ans;
}
