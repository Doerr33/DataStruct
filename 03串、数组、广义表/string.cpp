#define MaxSize 10000
#include<stdio.h>
typedef struct {
	char data[MaxSize];
	int length;
}SqString; //顺序串的静态分配实现


// 生成串 StrAssign(&s, cstr)
void StrAssign(SqString &s, char cstr[]) {
    // 传递一个字符数组挨个复制
	int i = 0;
	for (; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
} 


// 串的复制 StrCopy(&s, t)
void StrCopy(SqString &s, SqString t) {
    // 挨个复制
	for (int i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}


// 判断串相等 StrEqual(s, t)
bool StrEqual(SqString s, SqString t) {
    // 标记是否相等
	bool same = true;
    // 先判断长度是否相等
	if (s.length != t.length) same = false;
	else
    // 长度相等进一步挨个判断，有一个不相等就是不相等
		for (int i = 0; i < s.length; i++)
			if (s.data[i] != t.data[i]) {
				same = false;
				break;
			}
    if(same){
        printf("相同\n");
    }
	return same;
}


// 串的连接 Concat(s, t)
SqString Concat(SqString s, SqString t) {
	SqString str;
    // 创建一个字符串：设置长度为二者之和
	str.length = s.length + t.length;


    // 将第一个挨个复制到新字符串中
	for (int i = 0; i < s.length; i++)
		str.data[i] = s.data[i];


	for (int i = 0; i < t.length; i++){
    // 将第二个字符串复制到新字符串长度后一个开始的后面
        str.data[s.length] = t.data[i];
        ++ s.length;
        printf("t：%c\n",t.data[i]);
    }
		
	return str;
}


// 求子串 SubStr(s, i, j)
// 求从第 i 个字符开始的由连续 j 个字符组成的子串
SqString SubStr(SqString s, int i, int j) {
	SqString str;
	str.length = 0;

	if (i <= 0 || i > s.length || j<0 || j>s.length - i + 1)
		return str;									//参数不正确时返回空串
	for (int k = i - 1; k < i + j - 1; k++)//从i-j
		str.data[k - i + 1] = s.data[k];//str的0-j - 1个元素
	str.length = j;
	return str;
}

// 子串的插入 InsStr(s1, i, s2)
// 将顺序串s2插入到顺序串s1的第 i (i<=i<=n+1) 个位置上
// 子串的插入
SqString InStr(SqString s1,int i,SqString s2){
    int j;
    SqString str;
    str.length=0;

    if(i<=0||i>s1.length+1)//不合法
        return str;

    for(j=0; j<i-1; j++)//先将前i-1个元素复制进新数组中
        str.data[j]=s1.data[j];

    for(j=0; j<s2.length; j++)//将j个数组加入新数组中
        str.data[i+j-1]=s2.data[j];

    for(j=i-1; j<s1.length ; j++)//将i和后面的全部加入
        str.data[s2.length+j]=s1.data[j];

    str.length=s1.length+s2.length;
    return str;
}


// 子串的删除 DelStr(s, i, j)
// 在顺序串中删去从第 i 个字符开始的长度为 j 的子串
SqString DelStr(SqString s, int i, int j) {
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || j<0 || j>s.length - i + 1)//判断合法性
		return str;

	for (int k = 0; k < i - 1; k++)//先将前i-1个放置到新的字符串变量中
		str.data[k] = s.data[k];
        
	for (int k = i + j - 1; k < s.length; k++)//在将i + j开始的放置新字符变量i开始的位置
		str.data[k - j] = s.data[k];

	str.length = s.length - j;
	return str;
}


// 子串的替换 RepStr(s, i, j, t)
// 在顺序串s中将第i个字符开始的连续 j 个字符构成的子串用顺序串t替换
SqString RepStr(SqString s, int i, int j, SqString t) {
	SqString str;
	str.length = 0;

	if (i <= 0 || i > s.length || j<0 || j>s.length - i + 1)//判断是否合法
		return str;

	for (int k = 0; k < i - 1; k++)//先将前i - 1，放入新变量
		str.data[k] = s.data[k];

	for (int k = 0; k < t.length; k++)//插入t的字符
		str.data[i + k - 1] = t.data[k];

	for (int k = i + j - 1; k < s.length; k++)//将s中后面剩余的字符插入
		str.data[t.length + k - j] = s.data[k];

	str.length = i + t.length - 1;// 长度为i - 1加上j
	return str;
}


// 输出字符串
void DispStr(SqString s) {
	if (s.length > 0) {
		for (int i = 0; i < s.length; i++){
            printf("%c ",s.data[i]);
        }
        printf("\n");
	}
}

int main(){
    SqString s1;
    // 初始化字符串
    char a[100] = "helloworld";
    StrAssign(s1,a);
    printf("s1：\n");
    DispStr(s1);

    // 复制字符串返回的变量是S2，将s1复制到s2
    SqString s2;
    StrCopy(s2,s1);
    printf("s2：\n");
    DispStr(s2);
    
    // 判断字符串相等
    StrEqual(s1,s2);
    

    // 连接字符串
    SqString s3 = Concat(s1,s2);
    DispStr(s3);


    // 求字串i-j
    SqString s4;
    s4 = SubStr(s3,1,5);
    DispStr(s4);


    // 字串的插入
    SqString s5;
    s5 = InStr(s1,5,s2);
    DispStr(s5);


	// 删除子串
	SqString s6;
	s6 = DelStr(s5,5,10);
	DispStr(s6);


	// 替换子串
	SqString s7;
	SqString s8;
	char b[] = "jackz";
	StrAssign(s8,b);
	s7 = RepStr(s5,5,10,s8);
	DispStr(s7);
    return 0;
}




