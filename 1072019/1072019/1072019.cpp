// 1072019.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//若兄弟姊妹有明確要求(年長、年幼)可能會錯
//如果有我的關係，性別可能會錯
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


//1:無 2：男 3：女
int mysex = 1;
//一筆稱謂資料
struct result_infor {
	string appellation;
	bool is_male = true;
};
class judge {
public:
	//自己
	string myself(bool male, string r,string n) {
		if (male == true) {
			if (r == "爸爸") return "父親";
			else if (r == "兒子(較年輕)" || r == "兒子(較年長)") return "兒子";
			else if (r == "哥哥(較年長)" || r == "哥哥") return "哥哥";
			else if (r == "弟弟(較年輕)" || r == "弟弟") return "弟弟";
			else if (r == "我(男)" || r == "我(女)"||r =="我") return "自己";
			else if (mysex == 3 || mysex == 1) {
				if (r == "丈夫") {
					mysex = 3;
					return "夫";
				}			
			}
		}
		else {
			if (r == "媽媽") return "母親";
			else if (r == "女兒(較年輕)" || r == "女兒(較年長)") return "女兒";
			else if (r == "姊姊(較年長)" || r == "姊姊") return "姊姊";
			else if (r == "妹妹(較年輕)" || r == "妹妹") return "妹妹";
			else if (r == "我(男)" || r == "我(女)"|| r == "我") return "自己";
			else if (mysex == 2 || mysex == 1) {
				if (r == "妻子") {
					mysex = 2;
					return "妻";
				}
			}
		}
		return r;
	}
	//父親
	string father(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "祖父";
			else if (r == "哥哥" || r == "哥哥(較年長)") return "伯父";
			else if (r == "弟弟" || r == "弟弟(較年輕)") return "叔父";
			else if (r == "兒子(較年長)") return "哥哥";
			else if (r == "兒子(較年輕)") return "弟弟";
			else if (r == "兒子") {
				if (mysex == 1 || mysex == 2) return "自己";
				else return "哥哥";
			}
			else if (r == "我" || r == "我(男)") return "父親";
		}
		else {
			if (r == "媽媽") return "祖母";
			else if (r == "姊姊" || r == "妹妹" || r == "姊姊(較年長)" || r == "妹妹(較年輕)") return "姑媽";
			else if (r == "妻子") return "母親";
			else if (r == "女兒(較年長)") return "姊姊";
			else if (r == "女兒(較年輕)") return "妹妹";
			else if (r == "女兒") {
				if (mysex == 1 || mysex == 3) return "自己";
				else return "姊姊";
			}
		}
		return "父親";//不應該出來
	}
	//母親
	string mother(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "外祖父";
			else if (r == "哥哥" || r == "弟弟"|| r == "哥哥(較年長)"/*|| r == "哥哥(較年輕)"|| r == "弟弟(較年長)" */|| r == "弟弟(較年輕)") return "舅舅";
			else if (r == "丈夫") return "父親";
			else if (r == "兒子(較年長)") return "哥哥";
			else if (r == "兒子(較年輕)") return "弟弟";
			else if (r == "兒子") {
				if (mysex == 1 || mysex == 2) return "自己";
				else return "哥哥";
			}
			//else if (r == "我") return "母親";
		}
		else {
			if (r == "媽媽") return "外祖母";
			//也有可是媽媽
			else if (r == "姊姊" || r == "妹妹" || r == "姊姊(較年輕)" || r == "姊姊(較年長)" || r == "妹妹(較年輕)" || r == "妹妹(較年長)") return "姨媽";
			else if (r == "女兒(較年長)") return "姊姊";
			else if (r == "女兒(較年輕)") return "妹妹";
			else if (r == "女兒") {
				if (mysex == 1 || mysex == 3) return "自己";
				else return "姊姊";
			}
			else if (r == "我" || r == "我(女)") return "母親";
		}
		return "母親";
	}
	//姊姊、姊夫
	string older_sister(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "父親";
			else if (r == "哥哥(較年長)" || r == "哥哥(較年輕)" || r == "弟弟(較年長)") return "哥哥";
			else if (r == "弟弟(較年輕)") return "弟弟";
			else if (r == "哥哥" || r == "弟弟") return "哥哥";
			//else if (r == "丈夫") return "姊夫";
			else if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			//else if (r == "我(男)") return "姊夫";
			else if (r == "我") return n;
			else return "姊夫";
		}
		else {
			if (r == "媽媽") return "母親";
			//else if (r == "姊姊(較年長)"|| r == "姊姊(較年輕)" || r == "妹妹(較年長)") return "姊姊";
			else if (r == "妹妹(較年輕)") return "妹妹";
			//else if (r == "姊姊" || r == "妹妹") return "姊姊";
			//else if (r == "妻子") return "姊姊";
			else if (r == "女兒" || r =="女兒(較年長)" || r == "女兒(較年輕)") return "外甥女";
			//else if (r == "我(女)") return "姊姊";
			else return "姊姊";
		}
	}
	//哥哥、嫂嫂
	string older_bother(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "父親";
			//else if (r == "哥哥(較年長)" || r == "哥哥(較年輕)" || r == "弟弟(較年長)") return "哥哥";
			else if (r == "弟弟(較年輕)") return "弟弟";
			//else if (r == "哥哥" || r == "弟弟") return "哥哥";
			//else if (r == "丈夫") return "哥哥";
			else if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "姪子";
			//else if (r == "我(男)") return "哥哥";
			else if (r == "我") return n;
			else return "哥哥";
		}
		else {
			if (r == "媽媽") return "母親";
			else if (r == "姊姊(較年長)" || r == "姊姊(較年輕)"|| r == "妹妹(較年長)") return "姊姊";
			else if (r == "妹妹(較年輕)") return "妹妹";
			else if (r == "姊姊" || r == "妹妹") return "姊姊";
			//else if (r == "妻子") return "嫂嫂";
			else if (r == "女兒" || r == "女兒(較年輕)" || r == "女兒(較年長)") return "姪女";
			//else if (r == "我(女)") return "嫂嫂";
			else return "嫂嫂";
		}
	}
	//妹妹、妹夫
	string younger_sister(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "父親";
			else if (r == "哥哥(較年長)") return "哥哥";
			else if (r == "哥哥(較年輕)"|| r == "弟弟(較年長)" || r == "弟弟(較年輕)") return "弟弟";
			else if (r == "弟弟" || r == "哥哥") return "弟弟";
			//else if (r == "丈夫") return "妹夫";
			else if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			//else if (r == "我(男)") return "妹夫";
			else if (r == "我") return n;
			else return "妹夫";
		}
		else {
			if (r == "媽媽") return "母親";
			else if (r == "姊姊(較年長)") return "姊姊";
			//else if (r == "姊姊(較年輕)"|| r == "妹妹(較年長)"|| r == "妹妹(較年輕)") return "妹妹";
			//else if (r == "妹妹" || r == "姊姊") return "妹妹";
			//else if (r == "妻子") return "妹妹";
			else if (r == "女兒" || r == "女兒(較年輕)" || r == "女兒(較年長)") return "外甥女";
			else return "妹妹";
		}
	}
	//弟弟、弟媳
	string younger_bother(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "父親";
			else if (r == "哥哥(較年長)") return "哥哥";
			//else if (r == "哥哥(較年輕)"|| r == "弟弟(較年長)"|| r == "弟弟(較年輕)") return "弟弟";
			//else if (r == "弟弟" || r == "哥哥") return "弟弟";
			//else if (r == "丈夫") return "弟弟";
			else if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "姪子";
			else if (r == "我") return n;
			else return "弟弟";
		}
		else {
			if (r == "媽媽") return "母親";
			else if (r == "姊姊(較年長)") return "姊姊";
			else if (r == "姊姊(較年輕)"|| r == "妹妹(較年長)" || r == "妹妹(較年輕)") return "妹妹";
			else if (r == "妹妹" || r == "姊姊") return "妹妹";
			//else if (r == "妻子") return "弟媳";
			else if (r == "女兒" || r == "女兒(較年輕)" || r == "女兒(較年長)") return "姪女";
			else return "弟媳";
		}
	}
	//舅舅、舅媽都算在內
	string mother_bother(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "外祖父";
			/*else if (r == "哥哥" || r == "弟弟" 
				|| r == "哥哥(較年長)" || r == "哥哥(較年輕)" 
				|| r == "弟弟(較年輕)" || r == "弟弟(較年長)") return "舅舅";*/
			//else if (r == "丈夫") return "舅舅";
			else if (r == "兒子(較年長)") return "表兄";
			else if (r == "兒子(較年輕)") return "表弟";
			else if (r == "兒子") return "表弟";
			//else if (r == "我") return n;
			else return "舅舅";
		}
		else {
			if (r == "媽媽") return "外祖母";
			//有可能是媽媽
			else if (r == "姊姊" || r == "妹妹"
				|| r == "姊姊(較年長)" || r == "姊姊(較年輕)"
				|| r == "妹妹(較年輕)" || r == "妹妹(較年長)") return "姨媽";
			//else if (r == "妻子") return "舅媽";
			else if (r == "女兒(較年長)") return "表姊";
			else if (r == "女兒(較年輕)") return "表妹";
			else if (r == "女兒") return "表妹";
			else return "舅媽";
		}
	}
	//姨媽、姨丈
	string mother_sister(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "外祖父";
			else if (r == "哥哥" || r == "弟弟"
				|| r == "哥哥(較年長)" || r == "哥哥(較年輕)"
				|| r == "弟弟(較年輕)" || r == "弟弟(較年長)") return "舅舅";
			//else if (r == "丈夫") return "姨丈";
			else if (r == "兒子(較年長)") return "表兄";
			else if (r == "兒子(較年輕)") return "表弟";
			else if (r == "兒子") return "表弟";
			else if (r == "我") return n;
			else return "姨丈";
		}
		else {
			if (r == "媽媽") return "外祖母";
			/*else if (r == "姊姊" || r == "妹妹"
				|| r == "姊姊(較年長)" || r == "姊姊(較年輕)"
				|| r == "妹妹(較年輕)" || r == "妹妹(較年長)") return "姨媽"; */    //有可能是媽媽
			//else if (r == "妻子") return "姨媽";
			else if (r == "女兒(較年長)") return "表姊";
			else if (r == "女兒(較年輕)") return "表妹";
			else if (r == "女兒") return "表妹";
			else return "姨媽";
		}
	}
	//外祖父、外祖母
	string mother_parents(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子"|| r == "兒子(較年長)" || r == "兒子(較年輕)") return "舅舅";
			else if (r == "我") return n;
			else /*if(r == "丈夫")*/ return "外祖父";
		}
		else {
			if (r == "女兒"|| r == "女兒(較年長)"|| r == "女兒(較年輕)") return "姨媽";        //可能是媽媽
			else /*if (r == "妻子")*/ return "外祖母";
		}
	}
	//祖父、祖母
	string father_parents(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子") return "父親";
			else if (r == "兒子(較年輕)") return "叔父";
			else if (r == "兒子(較年長)") return "伯父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/ return "祖父";
		}
		else {
			if (r == "女兒" || r == "女兒(較年輕)" || r == "女兒(較年長)") return "姑媽";
			else /*if (r == "妻子")*/ return "祖母";
		}
	}
	//伯母、伯父
	string father_Obother(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "祖父";
			else if (r == "弟弟(較年輕)" || r == "弟弟") return "叔父";
			//else if (r == "哥哥" || r == "哥哥(較年長)" || r == "哥哥(較年輕)"/*不應該出現*/|| r == "弟弟(較年長)") return "伯父";
			//else if (r == "丈夫") return "伯父";
			else if (r == "兒子(較年長)") return "堂兄";
			else if (r == "兒子(較年輕)" || r == "兒子") return "堂弟";
			else return "伯父";
		}
		else {
			if (r == "媽媽") return "祖母";
			else if (r == "姊姊" || r == "妹妹" || r == "姐姐(較年輕)"|| r == "姐姐(較年長)" || r == "妹妹(較年輕)" || r == "妹妹(較年長)") return "姑媽";
			//else if (r == "妻子") return "伯母";
			else if (r == "女兒(較年長)") return "堂姊";
			else if (r == "女兒" || r == "女兒(較年輕)") return "堂妹";
			else if (r == "我") return n;
			else return "伯母";

		}
	}
	//叔父、嬸嬸
	string father_Ybother(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "祖父";
			//else if (r == "弟弟" || r == "哥哥(較年輕)" || r == "弟弟(較年輕)") return "叔父";
			else if (r == "哥哥" || r == "弟弟(較年長)"/*不應該出現*/ || r == "哥哥(較年長)") return "伯父";
			else if (r == "丈夫") return "叔父";
			else if (r == "兒子(較年長)") return "堂兄";
			else if (r == "兒子(較年輕)" || r == "兒子") return "堂弟";
			else if (r == "我") return n;
			else return "叔父";
		}
		else {
			if (r == "媽媽") return "祖母";
			else if (r == "姊姊" || r == "妹妹" || r == "姐姐(較年輕)" || r == "姐姐(較年長)" || r == "妹妹(較年輕)" || r == "妹妹(較年長)") return "姑媽";
			//else if (r == "妻子") return "嬸嬸";
			else if (r == "女兒(較年長)") return "堂姊";
			else if (r == "女兒" || r == "女兒(較年輕)") return "堂妹";
			else return "嬸嬸";

		}
	}
	//姑媽、姑丈
	string father_sister(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "祖父";
			else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)") return "叔父";
			else if (r == "哥哥" || r == "弟弟" || r == "弟弟(較年長)" || r == "哥哥(較年長)") return "伯父";
			//else if (r == "丈夫") return "姑丈";
			else if (r == "兒子(較年長)") return "表兄";
			else if (r == "兒子(較年輕)" || r == "兒子") return "表弟";
			else if (r == "我") return n;
			else return "姑丈";
		}
		else {
			if (r == "媽媽") return "祖母";
			//else if (r == "姊姊" || r == "妹妹" || r == "姐姐(較年輕)" || r == "姐姐(較年長)" || r == "妹妹(較年輕)" || r == "妹妹(較年長)") return "姑媽";
			//else if (r == "妻子") return "姑媽";
			else if (r == "女兒(較年長)") return "表姊";
			else if (r == "女兒" || r == "女兒(較年輕)") return "表妹";
			else return "姑媽";

		}
	}
	//妻子
	string wife(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "妻父";
			else if (r == "弟弟" || r == "弟弟(較年輕)") return "妻弟";
			else if (r == "哥哥" || r == "哥哥(較年長)") return "妻兄";
			else if (r == "丈夫" && (mysex == 1 || mysex == 3)) return "夫";
			else if (r == "丈夫" && (mysex == 1 || mysex == 2)) return "自己";
			else if (r == "兒子" || r == "兒子(較年長)" || r == "兒子(較年輕)") return "兒子";
		}
		else {
			if (r == "媽媽") return "妻母";
			//有可能是媽媽
			else if (r == "姊姊" || r == "姊姊(較年長)") return "妻姊";
			else if (r == "妹妹" || r == "妹妹(較年輕)") return "妻妹";
			else if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "女兒";
		}
		return "妻";
	}
	//夫
	string husband(bool male, string r, string n) {
		if (male == true) {
			if (r == "爸爸") return "夫父";
			else if (r == "弟弟" || r == "弟弟(較年輕)") return "夫弟";
			else if (r == "哥哥" || r == "哥哥(較年長)") return "夫兄";
			else if (r == "兒子" || r == "兒子(較年長)" || r == "兒子(較年輕)") return "兒子";
		}
		else {
			if (r == "媽媽") return "夫母";
			else if (r == "姊姊" || r == "姊姊(較年長)") return "夫姊";
			else if (r == "妹妹" || r == "妹妹(較年輕)") return "夫妹";
			else if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "女兒";
			else if (r == "妻子" && (mysex == 1 || mysex == 2)) return "妻";
			else if (r == "妻子" && (mysex == 1 || mysex == 3)) return "自己";
		}
		return "夫";
	}
	//妻母、妻父
	string wife_parents(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子(較年長)" || r == "兒子") return "妻兄";
			else  if (r == "兒子(較年輕)") return "妻弟";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/ return "妻父";

		}
		else {
			if (r == "女兒(較年長)" || r == "女兒") return "妻姊";
			else if (r == "女兒(較年輕)") return "妻妹";
			else /*if (r == "妻子")*/ return "妻母";
		}
	}
	//夫父、夫母
	string husband_parents(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子(較年長)" || r == "兒子") return "夫兄";
			else  if (r == "兒子(較年輕)") return "夫弟";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/ return "夫父";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)") return "夫姊";
			else if (r == "女兒(較年輕)") return "夫妹";
			else /*if (r == "妻子")*/ return "夫母";
		}
	}
	//妻兄、妻兄嫂
	string wife_Obother(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			//else if (r == "哥哥" || r == "哥哥(較年長)" || r == "弟弟(較年長)") return "妻兄";
			else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)"  /*不應該出現*/ || r == "弟弟") return "妻弟";
			else if (r == "爸爸") return "妻父";
			else if (r == "我") return n;
			else/* if (r == "丈夫")*/return "妻兄";

		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)" || r == "妹妹(較年長)") return "外甥女";
			else if (r == "姊姊"  || r == "姊姊(較年長)" || r == "妹妹(較年長)") return "妻姊";
			else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)"/*不應該出現*/ ) return "妻妹";
			else if (r == "妹妹") return "妻";
			else if (r == "媽媽") return "妻母";
			else /*if (r == "妻子")*/ return "妻兄嫂";
		}
	}
	//妻弟、妻弟媳
	string wife_Ybother(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			else if (r == "哥哥" || r == "弟弟(較年長)"/*不應該出現*/ || r == "哥哥(較年長)") return "妻兄";
			//else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)" || r == "弟弟") return "妻弟";
			else if (r == "爸爸") return "妻父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/ return "妻弟";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "外甥女";
			else if (r == "妹妹(較年長)"/*不應該出現*/ || r == "姊姊(較年長)" ) return "妻姊";
			else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)" || r == "妹妹") return "妻妹";
			else if (r == "姊姊") return "妻";
			else if (r == "媽媽") return "妻母";
			else /*if (r == "妻子")*/  return"妻弟媳";
		}
	}
	//妻姊、妻姊夫
	string wife_Osister(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			else if (r == "哥哥" || r == "弟弟(較年長)" || r == "哥哥(較年長)") return "妻兄";
			else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)" /*不應該出現*/|| r == "弟弟") return "妻弟";
			else if (r == "爸爸") return "妻父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/return "妻姊夫";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "外甥女";
			//else if (r == "妹妹(較年長)" || r == "姊姊(較年長)" || r == "姊姊") return "妻姊";
			else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)" /*不應該出現*/ ) return "妻妹";
			else if (r == "妹妹") return "妻";
			else if (r == "媽媽") return "妻母";
			else /*if (r == "妻子")*/ return "妻姊";
		}
	}
	//妻妹、妻妹夫
	string wife_Ysister(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			else if (r == "哥哥" || r == "弟弟(較年長)"/*不應該出現*/ || r == "哥哥(較年長)") return "妻兄";
			else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)" || r == "弟弟") return "妻弟";
			else if (r == "爸爸") return "妻父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/return "妻妹夫";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "外甥女";
			else if (r == "妹妹(較年長)"/*不應該出現*/ || r == "姊姊(較年長)") return "妻姊";
			//else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)" || r == "妹妹") return "妻妹";
			else if (r == "姊姊") return "妻";
			else if (r == "媽媽") return "妻母";
			else /*if (r == "妻子")*/  return"妻妹";
		}
	}
	//夫兄、夫兄嫂
	string husband_Obother(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "姪子";
			//else if (r == "哥哥" || r == "弟弟(較年長)" || r == "哥哥(較年長)") return "夫兄";
			else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)"/*不應該出現*/) return "夫弟";
			else if (r == "弟弟") return "夫";
			else if (r == "爸爸") return "夫父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/return "夫兄";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "姪女";
			else if (r == "妹妹(較年長)" || r == "姊姊(較年長)" || r == "姊姊") return "夫姊";
			else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)"/*不應該出現*/ || r == "妹妹") return "夫妹";
			else if (r == "媽媽") return "夫母";
			else /*if (r == "妻子")*/  return"夫兄嫂";
		}
	}
	//夫弟、夫弟媳
	string husband_Ybother(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "姪子";
			else if (r == "弟弟(較年長)"/*不應該出現*/ || r == "哥哥(較年長)") return "夫兄";
			//else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)" || r == "弟弟") return "夫弟";
			else if (r == "哥哥") return "夫";
			else if (r == "爸爸") return "夫父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/return "夫弟";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "姪女";
			else if (r == "妹妹(較年長)" /*不應該出現*/ || r == "姊姊(較年長)" || r == "姊姊") return "夫姊";
			else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)" || r == "妹妹") return "夫妹";
			else if (r == "媽媽") return "夫母";
			else /*if (r == "妻子")*/  return"夫弟媳";
		}
	}
	//夫姊、夫姊夫
	string husband_Osister(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			else if (r == "弟弟(較年長)" || r == "哥哥(較年長)" || r == "哥哥") return "夫兄";
			else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)"/*不應該出現*/) return "夫弟";
			else if (r == "弟弟") return "夫";
			else if (r == "爸爸") return "夫父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/return "夫姊夫";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "外甥女";
			//else if (r == "妹妹(較年長)" || r == "姊姊(較年長)" || r == "姊姊") return "夫姊";
			else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)" || r == "妹妹") return "夫妹";
			else if (r == "媽媽") return "夫母";
			else /*if (r == "妻子")*/  return"夫姊";
		}
	}
	//夫妹、夫妹夫
	string husband_Ysister(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外甥";
			else if (r == "弟弟(較年長)"/*不應該出現*/ || r == "哥哥(較年長)") return "夫兄";
			else if (r == "弟弟(較年輕)" || r == "哥哥(較年輕)" || r == "弟弟") return "夫弟";
			else if (r == "哥哥") return "夫";
			else if (r == "爸爸") return "夫父";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/return "夫妹夫";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "外甥女";
			else if (r == "妹妹(較年長)"/*不應該出現*/ || r == "姊姊(較年長)" || r == "姊姊") return "夫姊";
			//else if (r == "妹妹(較年輕)" || r == "姊姊(較年輕)" || r == "妹妹") return "夫妹";
			else if (r == "媽媽") return "夫母";
			else /*if (r == "妻子")*/  return"夫妹";
		}
	}
	//女兒、女婿
	string daughter(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "外孫";
			else if (r == "弟弟(較年長)" || r == "哥哥(較年長)" || r == "哥哥" || r == "弟弟(較年輕)" || r == "哥哥(較年輕)" || r == "弟弟") return "兒子";
			else if (r == "爸爸" && (mysex == 1 || mysex == 3)) return "夫";
			else if (r == "爸爸" && (mysex == 1 || mysex == 2)) return "自己";
			else if (r == "我") return n;
			else /*if (r == "丈夫")*/return "女婿";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "外孫";
			//else if (r == "妹妹(較年長)" || r == "姊姊(較年長)" || r == "姊姊" || r == "妹妹(較年輕)" || r == "姊姊(較年輕)" || r == "妹妹") return "女兒";
			else if (r == "媽媽" && (mysex == 1 || mysex == 2)) return "妻";
			else if (r == "媽媽" && (mysex == 1 || mysex == 3)) return "自己";
			else /*if (r == "妻子")*/  return"女兒";
		}
	}
	//兒子、媳婦
	string son(bool male, string r, string n) {
		if (male == true) {
			if (r == "兒子" || r == "兒子(較年輕)" || r == "兒子(較年長)") return "孫子";
			//else if (r == "弟弟(較年長)" || r == "哥哥(較年長)" || r == "哥哥" || r == "弟弟(較年輕)" || r == "哥哥(較年輕)" || r == "弟弟") return "兒子";
			else if (r == "爸爸" && (mysex == 1 || mysex == 3)) return "夫";
			else if (r == "爸爸" && (mysex == 1 || mysex == 2)) return "自己";
			else if (r == "我") return n;
			else return "兒子";
		}
		else {
			if (r == "女兒" || r == "女兒(較年長)" || r == "女兒(較年輕)") return "孫女";
			else if (r == "妹妹(較年長)" || r == "姊姊(較年長)" || r == "姊姊" || r == "妹妹(較年輕)" || r == "姊姊(較年輕)" || r == "妹妹") return "女兒";
			else if (r == "媽媽" && (mysex == 1 || mysex == 2)) return "妻";
			else if (r == "媽媽" && (mysex == 1 || mysex == 3)) return "自己";
			else /*if (r == "妻子")*/  return"媳婦";
		}
	}
};
class relate {
	judge j;
public:
	bool sex(string r) {
		if (r == "爸爸" || r == "哥哥" || r == "弟弟" || r == "丈夫" || r == "兒子(較年長)" ||r == "我"||r == "我(男)"
			|| r == "兒子(較年輕)" || r == "兒子" || r == "哥哥(較年長)" || r == "哥哥(較年輕)" ||
			r == "弟弟(較年長)" || r == "弟弟(較年輕)")
			return true;
		else
			return false;
	}
	string changeCall(string n) {
		if (n == "爸爸") return "父親";
		else if (n == "媽媽") return "母親";
		else if (n == "丈夫") { mysex = 3; return "夫"; }
		else if (n == "妻子") { mysex = 2; return "妻"; }
		else if (n == "哥哥(較年長)") return "哥哥";
		else if (n == "弟弟(較年輕)") return "弟弟";
		else if (n == "妹妹(較年輕)") return "妹妹";
		else if (n == "姊姊(較年輕)") return "姊姊";
		else if (n == "兒子(較年輕)" || n == "兒子" || n == "兒子(較年長)") return "兒子";
		else if (n == "女兒(較年輕)" || n == "女兒" || n == "女兒(較年長)") return "女兒";
		else if (n == "我") return "自己";
		else if (n == "我(女)") { mysex = 3; return "自己"; }
		else if (n == "我(男)") { mysex = 2; return "自己"; }
		else return n;
	}
	string search(string n, bool male, string r, vector<result_infor>& records) {
		
		if (n == "自己" /*|| n == "自己(男)" || n == "自己(女)"*/) return j.myself(male, r, n);
		else if (n == "父親") return j.father(male, r, n);
		else if (n == "母親") return j.mother(male, r,n);
		else if (n == "姊姊" || n == "姊夫") return j.older_sister(male, r, n);
		else if (n == "哥哥" || n == "嫂嫂") return j.older_bother(male, r, n);
		else if (n == "妹妹" || n == "妹夫") return j.younger_sister(male, r, n);
		else if (n == "弟弟" || n == "弟媳") return j.younger_bother(male, r, n);
		else if (n == "舅舅" || n == "舅媽")return j.mother_bother(male, r, n);
		else if (n == "姨媽" || n == "姨丈")return j.mother_sister(male, r, n);
		else if (n == "外祖父" || n == "外祖母") return j.mother_parents(male, r, n);
		else if (n == "外祖父" || n == "外祖母") return j.mother_parents(male, r, n);
		else if (n == "表兄" || n == "表弟" || n == "表姊" || n == "表妹") {
			if (r == "爸爸" || r == "媽媽") {
				if (records.size() > 1) { //防錯
					records.pop_back();
					string pre = records.back().appellation;
					while (pre == "表兄" || pre == "表弟" || pre == "表姊" || pre == "表妹") {
						records.pop_back();
						pre = records.back().appellation;
					}
					return search(records.back().appellation, male, " " , records);
				}
			}
			else {
				if (r == "我" || r == "我(男)" || r == "我(女)") return n;
				else if (male == true) {
					if (r == "哥哥" || r =="弟弟(較年長)" || r == "哥哥(較年長)") return "表兄";
					else if (r == "弟弟" || r == "弟弟(較年輕)" || r == "哥哥(較年輕)") return "表弟";
				}
				else {
					if (r == "姊姊" || r == "妹妹(較年長)" || r == "姊姊(較年長)") return "表姊";
					else if (r == "妹妹" || r == "妹妹(較年輕)" || r == "姊姊(較年輕)") return "表妹";
				}
			}
		}
		else if (n == "堂兄" || n == "堂弟" || n == "堂姊" || n == "堂妹") {
			if (r == "爸爸" || r == "媽媽") {
				if (records.size() > 1) { //防錯
					records.pop_back();
					string pre = records.back().appellation;
					while (pre == "堂兄" || pre == "堂弟" || pre == "堂姊" || pre == "堂妹") {
						records.pop_back();
						pre = records.back().appellation;
					}
					return search(records.back().appellation, male, " ", records);
				}
			}
			else {
				if (r == "我" || r == "我(男)" || r == "我(女)") return n;
				else if (male == true) {
					if (r == "哥哥" || r == "弟弟(較年長)" || r == "哥哥(較年長)") return "堂兄";
					else if (r == "弟弟" || r == "弟弟(較年輕)" || r == "哥哥(較年輕)") return "堂弟";
				}
				else {
					if (r == "姊姊" || r == "妹妹(較年長)" || r == "姊姊(較年長)") return "堂姊";
					else if (r == "妹妹" || r == "妹妹(較年輕)" || r == "姊姊(較年輕)") return "堂妹";
				}
			}
		}
		else if (n == "外甥女" || n == "外甥") {
			if (r == "我" || r == "我(男)" || r == "我(女)") return n;
			else if (r == "哥哥" || r =="哥哥(較年輕)" || r == "哥哥(較年長)" 
				|| r == "弟弟" || r == "弟弟(較年長)" || r == "弟弟(較年輕)") return "外甥";
			else if (r == "姊姊" || r == "姊姊(較年輕)" || r == "姊姊(較年長)" 
				|| r == "妹妹" || r == "妹妹(較年長)" || r == "妹妹(較年輕)") return "外甥女";
			else if (r == "爸爸" || r == "媽媽") {
				if (records.size() > 1) { //防錯
					records.pop_back();
					string pre = records.back().appellation;
					while (pre == "外甥女" || pre == "外甥") {
						records.pop_back();
						pre = records.back().appellation;
					}
					return search(records.back().appellation, male, " ", records);
				}
			}

		}
		else if (n == "姪子" || n == "姪女") {
			if (r == "我" || r == "我(男)" || r == "我(女)") return n;
			else if (r == "哥哥" || r == "哥哥(較年輕)" || r == "哥哥(較年長)"
				|| r == "弟弟" || r == "弟弟(較年長)" || r == "弟弟(較年輕)") return "姪子";
			else if (r == "姊姊" || r == "姊姊(較年輕)" || r == "姊姊(較年長)"
				|| r == "妹妹" || r == "妹妹(較年長)" || r == "妹妹(較年輕)") return "姪女";
			else if (r == "爸爸" || r == "媽媽") {
				if (records.size() > 1) { //防錯
					records.pop_back();
					string pre = records.back().appellation;
					while (pre == "姪子" || pre == "姪女") {
						records.pop_back();
						pre = records.back().appellation;
					}
					return search(records.back().appellation, male, " ", records);
				}
			}
		}
		else if (n == "祖父" || n == "祖母") return j.father_parents(male, r, n);
		else if (n == "伯父" || n == "伯母") return j.father_Obother(male, r, n);
		else if (n == "叔父" || n == "嬸嬸") return j.father_Ybother(male, r, n);
		else if (n == "姑媽" || n == "姑丈") return j.father_sister(male, r, n);
		else if (n == "妻") return j.wife(male, r, n);
		else if (n == "夫") return j.husband(male, r, n);
		else if (n == "妻父" || n == "妻母") return j.wife_parents(male, r, n);
		else if (n == "夫父" || n == "夫母") return j.husband_parents(male, r, n);
		else if (n == "妻兄" || n == "妻兄嫂") return j.wife_Obother(male, r, n);
		else if (n == "妻弟" || n == "妻弟媳") return j.wife_Ybother(male, r, n);
		else if (n == "妻姊" || n == "妻姊夫") return j.wife_Osister(male, r, n);
		else if (n == "妻妹" || n == "妻妹夫") return j.wife_Ysister(male, r, n);
		else if (n == "夫兄" || n == "夫兄嫂") return j.husband_Obother(male, r, n);
		else if (n == "夫弟" || n == "夫弟媳") return j.husband_Ybother(male, r, n);
		else if (n == "夫姊" || n == "夫姊夫") return j.husband_Osister(male, r, n);
		else if (n == "夫妹" || n == "夫妹夫") return j.husband_Ysister(male, r, n);
		else if (n == "女兒" || n == "女婿") return j.daughter(male, r, n);
		else if (n == "兒子" || n == "媳婦") return j.son(male, r, n);
		else if (n == "外孫") {
			if (r == "我" || r == "我(男)" || r == "我(女)") return n;
			else if (r == "哥哥" || r == "弟弟" 
				|| r == "姊姊" || r == "妹妹"
				|| r == "哥哥(較年長)" || r == "哥哥(較年輕)"
				|| r == "弟弟(較年長)" || r == "弟弟(較年輕)"
				|| r == "姊姊(較年長)" || r == "姊姊(較年輕)"
				|| r == "妹妹(較年長)" || r == "妹妹(較年輕)") return "外孫";
			else if (r == "爸爸" || r == "媽媽") {
				if (records.size() > 1) { //防錯
					records.pop_back();
					string pre = records.back().appellation;
					while (pre == "外孫") {
						records.pop_back();
						pre = records.back().appellation;
					}
					return search(records.back().appellation, male, " ", records);
				}
			}
		}
		else if (n == "孫子" || n == "孫女") {
			if (r == "我" || r == "我(男)" || r == "我(女)") return n;
			else if (r == "哥哥" || r == "弟弟"
				|| r == "哥哥(較年長)" || r == "哥哥(較年輕)"
				|| r == "弟弟(較年長)" || r == "弟弟(較年輕)") return "孫子";
			else if (r == "姊姊" || r == "妹妹"
					|| r == "姊姊(較年長)" || r == "姊姊(較年輕)"
					|| r == "妹妹(較年長)" || r == "妹妹(較年輕)") return "孫女";
			else if (r == "爸爸" || r == "媽媽") {
				if (records.size() > 1) { //防錯
					records.pop_back();
					string pre = records.back().appellation;
					while (pre == "孫子" || pre == "孫女") {
						records.pop_back();
						pre = records.back().appellation;
					}
					return search(records.back().appellation, male, " ", records);
				}
			}
		}
		return "";
	}
};

int main(int argc, char* argv[])
{
	ifstream fin;
	fin.open(argv[1]);

	string line;
	vector<string> Arelation;
	while (getline(fin, line)) {
		//cout << line << endl;
		int length = sizeof(line),i = 0;
		string::size_type position;
		
		while (line.find("的", i) != line.npos) {
			position = line.find("的", i);
			position -= i;
			string str = "";
			for (int j = 0; j < position;j++) {
				str += line[i + j];
			}
			//cout << str << endl;
			Arelation.push_back(str);
			i += position+3;
		}
		string str = "";
		for (int j = 0; i+j < line.length(); j++) {
			str += line[i + j];
		}
		//cout << str << endl << endl;
		Arelation.push_back(str);
		

		relate r;
		
		int index = 0,num = Arelation.size();
		string Relation, now = Arelation[index];
		result_infor searching;
		vector<result_infor> records;                              //歷史稱謂紀錄
		now = r.changeCall(now);
		
		searching.is_male = r.sex(now);
		searching.appellation = now;
		records.push_back(searching);

		index++;
		while (index < num) {
			Relation = Arelation[index];
			//判斷接下來性別
			if (Relation == "我") {
				searching.is_male = records.back().is_male;
			}
			else 
				searching.is_male = r.sex(Relation);

			searching.appellation = r.search(now, searching.is_male, Relation, records);
			records.push_back(searching);
			now = searching.appellation;
			index++;
		}
		cout /*<< "答: " */<< now /*<< endl*/ << endl;
		mysex = 1;
		Arelation.clear();
	
	}

	fin.close();
	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
