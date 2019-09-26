#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<Windows.h>
using namespace std;
string shen[32] = { "����","���","�ӱ�ʡ","ɽ��ʡ","���ɹ�������","����ʡ","����ʡ","������ʡ","�Ϻ�","����ʡ","�㽭ʡ","����ʡ","����ʡ","����ʡ","ɽ��ʡ","����ʡ","����ʡ","����ʡ","�㶫ʡ","����׳��������","����ʡ","����","�Ĵ�ʡ","����ʡ","����ʡ","����������","����ʡ","����ʡ","�ຣʡ","���Ļ���������","�½�ά���������" };
string shi1[100] = { "��ɽ��","�ػʵ���","������","��̨��","������","�żҿ���","�е���","������","�ȷ���","��ˮ��","̫ԭ��","��ͬ��","��Ȫ��","������","������","˷����","������","�˳���","������","�ٷ���","������","���ͺ�����","��ͷ��","�ں���","�����","ͨ����","������˹��","�����׶���","�����첼��","�˰���","���ֹ�����","��������","������","������","��ɽ��","��˳��","��Ϫ��","������","������","Ӫ����","������","�̽���","������","������","��«����","������","������","��ƽ��","��Դ��","ͨ����","��ɽ��","��ԭ��","�׳���","�ӱ߳�����������","��������","���������","������","�׸���","˫Ѽɽ��","������","������","��ľ˹��","��̨����","ĵ������","�ں���","�绯��","���˰������","�Ͼ���","������","������","������","������","��ͨ��","���Ƹ���","������","�γ���","������","����","̩����","��Ǩ��","������","������","������","������","������","������","����","������","��ɽ��","̨����","��ˮ��","�Ϸ���","�ߺ���","������","������","��ɽ��","������","ͭ����","������" };
string shi2[100] = { "��ɽ��","������","������","������","������","������","������","������","������","������","������","������","Ȫ����","������","������","������","�ϲ���","��������","�Ž���","������","ӥ̶��","������","������","�˴���","������","������","������","�ൺ��","�Ͳ���","��ׯ��","��Ӫ��","��̨��","Ϋ����","������","̩����","������","������","������","������","������","�ĳ���","������","������","֣����","������","������","ƽ��ɽ��","������","�ױ���","������","������","�����","�����","�����","����Ͽ��","������","������","������","�ܿ���","פ�����","ʡֱϽ�ؼ���������","�人��","��ʯ��","ʮ����","�˲���","������","������","������","Т����","������","�Ƹ���","������","������","��ʩ����������������","ʡֱϽ�ؼ���������","��ɳ��","������","��̶��","������","������","������","������","�żҽ���","������","������","������","������","¦����","��������������������","������","�ع���","������","�麣��","��ͷ��","��ɽ��","������","տ����","ï����" };
string shi3[100] = { "������","������","÷����","��β��","��Դ��","������","��Զ��","������","������","�Ƹ���","������","������","������","������","������","���Ǹ���","������","�����","������","��ɫ��","������","�ӳ���","������","������","������","������","��ɳ��","ʡֱϽ�ؼ���������","�ɶ���","�Թ���","��֦����","������","������","������","��Ԫ��","������","�ڽ���","�ϳ���","üɽ��","�˱���","�㰲��","������","�Ű���","������","������","���Ӳ���Ǽ��������","���β���������","��ɽ����������","������","����ˮ��","������","��˳��","�Ͻ���","ͭ����","ǭ���ϲ���������������","ǭ�������嶱��������","ǭ�ϲ���������������","������","������","��Ϫ��","��ɽ��","��ͨ��","������","�ն���","�ٲ���","��������������","��ӹ���������������","��ɽ׳������������","��˫���ɴ���������","�������������","�º���徰����������","ŭ��������������","�������������","������","�տ�����","������","��֥��","������","�������","������","ͭ����","������","������","μ����","�Ӱ���","������","������","������","������","������","��������","�����","������","��ˮ��","������","��Ҵ��","ƽ����","��Ȫ��","������" };
string shi4[100] = { "������","¤����","���Ļ���������","���ϲ���������","������","������","��������������","���ϲ���������","���ϲ���������","�������������","��������������","�����ɹ������������","������","ʯ��ɽ��","������","��ԭ��","������","��³ľ����","����������","��³����","������","��������������","���������ɹ�������","���������ɹ�������","�����յ���","�������տ¶�����������","��ʲ����","�������","���������������","���ǵ���","����̩����","������","�Ϻ���","������","�����" };

string GbkToUtf8(const char *src_str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, src_str, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, src_str, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	string strTemp = str;
	if (wstr) delete[] wstr;
	if (str) delete[] str;
	return strTemp;
}
string Utf8ToGbk(const char *src_str)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	string strTemp(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	return strTemp;
}
string FirstAdd(string a)
{
	string m;
	for(int i=0;i<32;i++)
	{
		if (shen[i][0] == a[0] && a[1] == shen[i][1] && a[2] == shen[i][2] && a[3] == shen[i][3])
		{
			m = shen[i];
			return m;
		}
	}
	m = "";
	return m;
}
string SecondAdd(string a)
{
	string m;
	for(int i=0;i<100;i++)
	{
		if (a[0] == shi1[i][0] && a[1] == shi1[i][1] && a[2] == shi1[i][2] && a[3] == shi1[i][3])
		{
			m = shi1[i];
			return m;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (a[0] == shi2[i][0] && a[1] == shi2[i][1] && a[2] == shi2[i][2] && a[3] == shi2[i][3])
		{
			m = shi2[i];
			return m;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (a[0] == shi3[i][0] && a[1] == shi3[i][1] && a[2] == shi3[i][2] && a[3] == shi3[i][3])
		{
			m = shi3[i];
			return m;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (a[0] == shi4[i][0] && a[1] == shi4[i][1] && a[2] == shi4[i][2] && a[3] == shi4[i][3])
		{
			m = shi4[i];
			return m;
		}
	}
	m = "";
	return m;
}



int main(int argc, char *argv[])//"D:/in.txt""D:/out.txt"
{
	ifstream ifs(argv[1]);
	string x;
	int count = 0;
	ofstream ofs(argv[2]);
	ofs << "[";
	while (getline(ifs, x))
	{
		x = Utf8ToGbk(x.c_str());
		if (count != 0)
			ofs << "," << endl;
		else
			ofs << endl;
		int i = 2;
		string Name, Num, Add1, Add2, Add3, Add4, Add5;
		string xm = "{\" ����\" : \"";
		string sj = "\",\"�ֻ�\" : \"";
		string dz = "\",\"��ַ\" : [\"";
		for (; x[i] != ','; i++)
			;
		Name = x.substr(2, i - 2);
		i++;
		for (int j = i, count = 0,flag=0,e=0;x[j]!='\0' ; j++)
		{
			if (x[j] >= '0'&&x[j]<='9')
			{
				if (flag == 0)
				{
					flag = 1;
					e = j;
				}
				count++;
				if (count == 11)
				{
					Num = x.substr(e, 11);
					int k = e + 11;
					for (; x[k] != '.'; k++, e++)
						x[e] = x[k];
					x[e] = '.';
					break;
				}
			}
			else
			{
				flag = 0;
				count = 0;
			}
		}
		string add1, add2, add3, add4, add5;
		if (i < (int)x.size() - 4)
			add1 = x.substr(i, 4);
		i += 4;
		Add1 = FirstAdd(add1);
		if ((int)add1.size() >= 2)
			if ((add1.substr(0, 2) == "��" || add1.substr(0, 2) == "��" || add1.substr(0, 2) == "��" || add1.substr(0, 2) == "��"))
			{
				i -= 4;
			}
		int a1 = (int)Add1.size();
		if (a1 > 4)
			i += (a1 - 6);
		if (i < (int)x.size() - 2)
			if (x.substr(i, 2) == "ʡ" || x.substr(i, 2) == "��") i += 2;
		if (i + 4 <= (int)x.size())
			add2 = x.substr(i, 4);
		i += 4;
		Add2 = SecondAdd(add2);
		if (Add2 == "")
		{
				i -= 4;
		}
		else
		{
			int a2 = (int)Add2.size();
			if (a2 > 4)
				i += (a2 - 6);
			if (i <= (int)x.size() - 4)
				if (x.substr(i, 2) == "��" || x.substr(i, 2) == "��" || x.substr(i, 2) == "��") i += 2;
		}
		int j = i;
		for (; i < (int)x.size() - 2; i += 2)
		{
			if (x.substr(i, 2) == "��" || x.substr(i, 2) == "��" || x.substr(i, 2) == "��")
			{
				Add3 = x.substr(j, i - j + 2);
				i += 2;
				j = i;
				break;
			}
		}
		if (Add3.empty())
			i = j;
		for (; i < (int)x.size() - 2; i += 2)
		{
			if (x.substr(i, 2) == "��" || x.substr(i, 2) == "��" || x.substr(i, 2) == "��")
			{
				Add4 = x.substr(j, i - j + 2);
				i += 2;
				j = i;
				break;
			}
		}
		if (x[0] == '1')
		{
			if (Add4.empty())
				i = j;
			for (; i < (int)x.size() && x[i] != '.'; i++)
				;
			Add5 = x.substr(j, i - j);
			Name = GbkToUtf8(Name.c_str());
			Add1 = GbkToUtf8(Add1.c_str());
			Add2 = GbkToUtf8(Add2.c_str());
			Add3 = GbkToUtf8(Add3.c_str());
			Add4 = GbkToUtf8(Add4.c_str());
			Add5 = GbkToUtf8(Add5.c_str());
			ofs << GbkToUtf8(xm.c_str()) << Name << GbkToUtf8(sj.c_str()) << Num << GbkToUtf8(dz.c_str()) << Add1 << "\",\"" << Add2 << "\",\"" << Add3 << "\",\"" << Add4 << "\",\"" << Add5 << "\"]}";
		}
		else if (x[0] == '2' || x[0] == '3')
		{
			string Add6, Add7;
			if (Add4.empty())
				i = j;
			for (; i < (int)x.size() - 2; i++)
			{
				if (x.substr(i, 2) == "·" || x.substr(i, 2) == "��")
				{
					Add5 = x.substr(j, i - j + 2);
					i += 2;
					j = i;
					break;
				}
			}
			for (; i < (int)x.size() && x.substr(i, 2) != "��"; i++)
				;
			i += 2;
			Add6 = x.substr(j, i - j);
			j = i;
			for (; i < (int)x.size() && x[i] != '.'; i++)
				;
			if (j < (int)x.size() - i + j)
				Add7 = x.substr(j, i - j);
			Name = GbkToUtf8(Name.c_str());
			Add1 = GbkToUtf8(Add1.c_str());
			Add2 = GbkToUtf8(Add2.c_str());
			Add3 = GbkToUtf8(Add3.c_str());
			Add4 = GbkToUtf8(Add4.c_str());
			Add5 = GbkToUtf8(Add5.c_str());
			Add6 = GbkToUtf8(Add6.c_str());
			Add7 = GbkToUtf8(Add7.c_str());
			ofs << GbkToUtf8(xm.c_str()) << Name << GbkToUtf8(sj.c_str()) << Num << GbkToUtf8(dz.c_str()) << Add1 << "\",\"" << Add2 << "\",\"" << Add3 << "\",\"" << Add4 << "\",\"" << Add5 << "\",\"" << Add6 << "\",\"" << Add7 << "\"]}";
		}
		count++;
	}
	ofs << endl << "]";
	return 0;
}