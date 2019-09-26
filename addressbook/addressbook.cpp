#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<Windows.h>
using namespace std;
string shen[32] = { "北京","天津","河北省","山西省","内蒙古自治区","辽宁省","吉林省","黑龙江省","上海","江苏省","浙江省","安徽省","福建省","江西省","山东省","河南省","湖北省","湖南省","广东省","广西壮族自治区","海南省","重庆","四川省","贵州省","云南省","西藏自治区","陕西省","甘肃省","青海省","宁夏回族自治区","新疆维吾尔自治区" };
string shi1[100] = { "唐山市","秦皇岛市","邯郸市","邢台市","保定市","张家口市","承德市","沧州市","廊坊市","衡水市","太原市","大同市","阳泉市","长治市","晋城市","朔州市","晋中市","运城市","忻州市","临汾市","吕梁市","呼和浩特市","包头市","乌海市","赤峰市","通辽市","鄂尔多斯市","巴彦淖尔市","乌兰察布市","兴安盟","锡林郭勒盟","阿拉善盟","沈阳市","大连市","鞍山市","抚顺市","本溪市","丹东市","锦州市","营口市","辽阳市","盘锦市","铁岭市","朝阳市","葫芦岛市","长春市","吉林市","四平市","辽源市","通化市","白山市","松原市","白城市","延边朝鲜族自治州","哈尔滨市","齐齐哈尔市","鸡西市","鹤岗市","双鸭山市","大庆市","伊春市","佳木斯市","七台河市","牡丹江市","黑河市","绥化市","大兴安岭地区","南京市","无锡市","徐州市","常州市","苏州市","南通市","连云港市","淮安市","盐城市","扬州市","镇江市","泰州市","宿迁市","杭州市","宁波市","温州市","嘉兴市","湖州市","绍兴市","金华市","衢州市","舟山市","台州市","丽水市","合肥市","芜湖市","蚌埠市","淮南市","马鞍山市","淮北市","铜陵市","安庆市" };
string shi2[100] = { "黄山市","滁州市","阜阳市","宿州市","六安市","亳州市","池州市","宣城市","福州市","厦门市","莆田市","三明市","泉州市","漳州市","龙岩市","宁德市","南昌市","景德镇市","九江市","新余市","鹰潭市","赣州市","吉安市","宜春市","抚州市","上饶市","济南市","青岛市","淄博市","枣庄市","东营市","烟台市","潍坊市","济宁市","泰安市","威海市","日照市","莱芜市","临沂市","德州市","聊城市","滨州市","菏泽市","郑州市","开封市","洛阳市","平顶山市","安阳市","鹤壁市","新乡市","焦作市","濮阳市","许昌市","漯河市","三门峡市","南阳市","商丘市","信阳市","周口市","驻马店市","省直辖县级行政区划","武汉市","黄石市","十堰市","宜昌市","襄阳市","鄂州市","荆门市","孝感市","荆州市","黄冈市","咸宁市","随州市","恩施土家族苗族自治州","省直辖县级行政区划","长沙市","株洲市","湘潭市","衡阳市","邵阳市","岳阳市","常德市","张家界市","益阳市","郴州市","永州市","怀化市","娄底市","湘西土家族苗族自治州","广州市","韶关市","深圳市","珠海市","汕头市","佛山市","江门市","湛江市","茂名市" };
string shi3[100] = { "肇庆市","惠州市","梅州市","汕尾市","河源市","阳江市","清远市","潮州市","揭阳市","云浮市","南宁市","柳州市","桂林市","梧州市","北海市","防城港市","钦州市","贵港市","玉林市","百色市","贺州市","河池市","来宾市","崇左市","海口市","三亚市","三沙市","省直辖县级行政区划","成都市","自贡市","攀枝花市","泸州市","德阳市","绵阳市","广元市","遂宁市","内江市","南充市","眉山市","宜宾市","广安市","达州市","雅安市","巴中市","资阳市","阿坝藏族羌族自治州","甘孜藏族自治州","凉山彝族自治州","贵阳市","六盘水市","遵义市","安顺市","毕节市","铜仁市","黔西南布依族苗族自治州","黔东南苗族侗族自治州","黔南布依族苗族自治州","昆明市","曲靖市","玉溪市","保山市","昭通市","丽江市","普洱市","临沧市","楚雄彝族自治州","红河哈尼族彝族自治州","文山壮族苗族自治州","西双版纳傣族自治州","大理白族自治州","德宏傣族景颇族自治州","怒江傈僳族自治州","迪庆藏族自治州","拉萨市","日喀则市","昌都市","林芝市","那曲市","阿里地区","西安市","铜川市","宝鸡市","咸阳市","渭南市","延安市","汉中市","榆林市","安康市","商洛市","兰州市","嘉峪关市","金昌市","白银市","天水市","武威市","张掖市","平凉市","酒泉市","庆阳市" };
string shi4[100] = { "定西市","陇南市","临夏回族自治州","甘南藏族自治州","西宁市","海东市","海北藏族自治州","黄南藏族自治州","海南藏族自治州","果洛藏族自治州","玉树藏族自治州","海西蒙古族藏族自治州","银川市","石嘴山市","吴忠市","固原市","中卫市","乌鲁木齐市","克拉玛依市","吐鲁番市","哈密市","昌吉回族自治州","博尔塔拉蒙古自治州","巴音郭楞蒙古自治州","阿克苏地区","克孜勒苏柯尔克孜自治州","喀什地区","和田地区","伊犁哈萨克自治州","塔城地区","阿勒泰地区","北京市","上海市","重庆市","天津市" };

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
		string xm = "{\" 姓名\" : \"";
		string sj = "\",\"手机\" : \"";
		string dz = "\",\"地址\" : [\"";
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
			if ((add1.substr(0, 2) == "北" || add1.substr(0, 2) == "上" || add1.substr(0, 2) == "重" || add1.substr(0, 2) == "天"))
			{
				i -= 4;
			}
		int a1 = (int)Add1.size();
		if (a1 > 4)
			i += (a1 - 6);
		if (i < (int)x.size() - 2)
			if (x.substr(i, 2) == "省" || x.substr(i, 2) == "区") i += 2;
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
				if (x.substr(i, 2) == "市" || x.substr(i, 2) == "州" || x.substr(i, 2) == "区") i += 2;
		}
		int j = i;
		for (; i < (int)x.size() - 2; i += 2)
		{
			if (x.substr(i, 2) == "区" || x.substr(i, 2) == "县" || x.substr(i, 2) == "旗")
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
			if (x.substr(i, 2) == "道" || x.substr(i, 2) == "镇" || x.substr(i, 2) == "乡")
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
				if (x.substr(i, 2) == "路" || x.substr(i, 2) == "村")
				{
					Add5 = x.substr(j, i - j + 2);
					i += 2;
					j = i;
					break;
				}
			}
			for (; i < (int)x.size() && x.substr(i, 2) != "号"; i++)
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