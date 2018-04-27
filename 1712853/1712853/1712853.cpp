#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>

struct sinhvien 
{
	wchar_t MSSV[11];
	wchar_t ten[40];
	wchar_t Khoa[50];
	wchar_t gmail[50];
	wchar_t kh[10];
	wchar_t namsinh[11];
	wchar_t hinhanh[16];
	wchar_t gioithieu[1001];
	wchar_t sothich[101];
};
wchar_t** danhsach(FILE *fi, int &n)
{
	
	wchar_t **arr = (wchar_t**)malloc(1 * sizeof(wchar_t*));
	
	while (n<10)
	{
		arr[n] = (wchar_t*)malloc(1500 * sizeof(wchar_t));
		fgetws(arr[n], 1500, fi);
		n++;
		arr = (wchar_t**)realloc(arr, (n + 1) * sizeof(wchar_t*));
		
		
	}
	return arr;
}
wint_t demskt(wchar_t *s)
{
	wint_t dem = 0;
	while (s[dem] != L'\0')
	{
		dem++;
	}
	return dem;
}
void saochep(wchar_t *&a, wchar_t *b)
{
	int j = demskt(a);
	for (int i = 0;i<j;i++)
		b[i] = a[i];

	b[j] = '\0';
}
sinhvien* doc(wchar_t a[])
{
	sinhvien* arr = (sinhvien*)malloc(sizeof(sinhvien));
	
	wchar_t *tt;
	tt = wcstok(a, L",");
	int dem=0;
	while (dem<9)
	{
		switch (dem)
		{
		case 0:saochep(tt, arr->MSSV);
		case 1:saochep(tt, arr->ten);
		case 2:saochep(tt, arr->Khoa);
		case 3:saochep(tt, arr->kh);
		case 4:saochep(tt, arr->namsinh);
		case 5:saochep(tt, arr->hinhanh);
		case 6:saochep(tt, arr->gioithieu);
		case 7:saochep(tt, arr->sothich);
		default:saochep(tt, arr->gmail);
			break;
		}
		tt = wcstok(NULL, L",");
		dem++;
	}

	return arr;
}
void dienfile(wchar_t *ten, sinhvien *sv)
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	FILE* fi = _wfopen(ten, L"w,ccs=UTF-16LE");
	fwprintf(fi, L"%s\n", L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(fi, L"%s\n", L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(fi, L"%s\n", L"	<head>\n");
	fwprintf(fi, L"%s\n", L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(fi, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(fi, L"		<title>HCMUS - %ls</title>\n", sv->ten);
	fwprintf(fi, L"%s\n", L"	</head>\n");
	fwprintf(fi, L"%s\n", L"		<div class=\"Layout_container\">\n");
	fwprintf(fi, L"%s\n", L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(fi, L"%s\n", L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(fi, L"%s\n", L"				<div><img id=\"logo\" src=\"hinhanh/logo.jpg\" height=\"105\" /></div>\n");
	fwprintf(fi, L"%s\n", L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
	fwprintf(fi, L"%s\n", L"			</div>\n");
	fwprintf(fi, L"%s\n", L"			<!-- End Layout Banner Region -->\n");
	fwprintf(fi, L"%s\n", L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(fi, L"%s\n", L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(fi, L"%s\n", L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(fi, L"%s\n", L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(fi, L"%s\n", L"					<!-- Begin Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fi, L"%s\n", L"					<div class=\"Personal_Location\"> \n");
	fwprintf(fi, L"%s\n", L"						<img src=\"hinhanh/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	fwprintf(fi, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv->ten, sv->MSSV);
	fwprintf(fi, L"%s\n", L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
	fwprintf(fi, L"%s\n", L"						<br />\n");
	fwprintf(fi, L"%s\n", L"						<div class=\"Personal_Phone\">\n");
	fwprintf(fi, L"%s\n", L"						</div>\n");
	fwprintf(fi, L"%s\n", L"						<br />\n");
	fwprintf(fi, L"%s\n", L"						<br />\n");
	fwprintf(fi, L"%s\n", L"					</div>\n");
	fwprintf(fi, L"%s\n", L"					<!-- End Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(fi, L"%s\n", L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	fwprintf(fi, L"						<img src=\"hinhanh/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->hinhanh);
	fwprintf(fi, L"%s\n", L"					</div>\n");
	fwprintf(fi, L"%s\n", L"				</div>\n");
	fwprintf(fi, L"%s\n", L"				<!-- End Below Banner Region -->\n");
	fwprintf(fi, L"%s\n", L"				<!-- Begin MainContents Region -->\n");
	fwprintf(fi, L"%s\n", L"				<div class=\"MainContain\">\n");
	fwprintf(fi, L"%s\n", L"\n");
	fwprintf(fi, L"%s\n", L"					<!-- Begin Top Region -->\n");
	fwprintf(fi, L"%s\n", L"					<div class=\"MainContain_Top\">\n");
	fwprintf(fi, L"%s\n", L"\n");
	fwprintf(fi, L"%s\n", L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(fi, L"%s\n", L"                       <div>\n");
	fwprintf(fi, L"%s\n", L"                            <ul class=\"TextInList\">\n");
	fwprintf(fi, L"<li>Họ và tên: %ls </li>\n<li>MSSV:%ls </li>", sv->ten, sv->MSSV);
	fwprintf(fi, L"								 <li>Sinh viên khoa %ls </li>\n", sv->Khoa);
	fwprintf(fi, L"								 <li>Gmail: %ls </li>\n", sv->gmail);
	fwprintf(fi, L"								 <li>Ngày sinh: %ls </li>\n", sv->namsinh);
	fwprintf(fi, L"								 <li>Sinh viên khoa %s </li>\n", sv->kh);
	fwprintf(fi, L"							 </ul>\n");
	fwprintf(fi, L"%s\n", L"						</div>\n");
	fwprintf(fi, L"%s\n", L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
	fwprintf(fi, L"%s\n", L"                       <div>\n");
	fwprintf(fi, L"%s\n", L"                            <ul class=\"TextInList\">\n");
	fwprintf(fi, L"                              <li>%ls</li>\n", sv->sothich);
	fwprintf(fi, L"%s\n", L"							 </ul>\n");
	fwprintf(fi, L"%s\n", L"						</div>\n");
	fwprintf(fi, L"%s\n", L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(fi, L"%s\n", L"						<div class=\"Description\">\n");
	fwprintf(fi, L"                            %ls\n", sv->gioithieu);
	fwprintf(fi, L"%s\n", L"						</div>\n");
	fwprintf(fi, L"%s\n", L"\n");
	fwprintf(fi, L"%s\n", L"					</div>\n");
	fwprintf(fi, L"%s\n", L"				</div>\n");
	fwprintf(fi, L"%s\n", L"			</div>\n");
	fwprintf(fi, L"%s\n", L"\n");
	fwprintf(fi, L"%s\n", L"			<!-- Begin Layout Footer -->\n");
	fwprintf(fi, L"%s\n", L"			<div class=\"Layout_Footer\">\n");
	fwprintf(fi, L"%s\n", L"				<div class=\"divCopyright\">\n");
	fwprintf(fi, L"%s\n", L"					<br />\n");
	fwprintf(fi, L"%s\n", L"					<img src=\"hinhanh/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(fi, L"%s\n", L"					<br />\n");
	fwprintf(fi, L"%s\n", L"				@2018</br>\n");
	fwprintf(fi, L"%s\n", L"				Ðồ án giữa kì</br>\n");
	fwprintf(fi, L"%s\n", L"				KĨ THUẬT LẬP TRÌNH</br>\n");
	fwprintf(fi, L"%s\n", L"				TH2018/03</br>\n");
	fwprintf(fi, L"%s\n", L"				1712853 - Châu Lâm Anh Tú</br>\n");
	fwprintf(fi, L"%s\n", L"				</div>\n");
	fwprintf(fi, L"%s\n", L"			</div>\n");
	fwprintf(fi, L"%s\n", L"			<!-- End Layout Footer -->\n");
	fwprintf(fi, L"%s\n", L"		</div>\n");
	fwprintf(fi, L"%s\n", L"	</body>\n");
	fwprintf(fi, L"%s\n", L"</html>");
	fclose(fi);
}

void main()
{
	FILE* fi = _wfopen(L"text.csv", L"rt,ccs=UTF-8");
	if (fi == NULL)
	{
		printf("khong the mo tap tin\n");
	}
	
	int n=0;
	wchar_t **arr = danhsach(fi, n);

	for (int i = 0;i<n;i++)
	{
		sinhvien *b = doc(arr[i]);
		wchar_t ten[40];
		wcscpy(ten,b->MSSV);
		wcscat(ten,L".html");
		dienfile(ten, b);
	}
	
	for (int j=0;j<n;j++)
	{
		delete []arr[j];
	}
	delete []arr;
	getch();
}