#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

void NhapKichThuocMaTran(int *, int *, int *, int *);
void NhapMaTran(int *, int, int);
void CongMaTran();
void NhanMaTran();
void InMaTran(int *, int, int );
void TinhDinhThuc();
int *TaoMaTranCon(int *, int , int );
int DinhThucDeQuy(int *, int );

int main()
{
    char ch;
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n");
        printf("CHUONG TRINH CONG VA NHAN HAI MA TRAN");
        printf("\n              1.Cong 2 ma tran");
        printf("\n              2.Nhan 2 ma tran");
        printf("\n              3.Tinh dinh thuc cua ma tran vuong");
        printf("\n        bam 1-3 de chon, phim khac de ket thuc: ");
        ch=getch();
        printf("\n\n");
        if (ch == '1')
            CongMaTran();
        else if (ch == '2')
            NhanMaTran();
        else if (ch == '3')
            TinhDinhThuc();
        else
        {
            printf("\n ARE YOU SURE ? Y/..");
            fflush(stdin);
            ch=getch();
            if (ch=='y'||ch=='Y')
                break;
        }
    }
}
void NhapKichThuocMaTran(int *a, int *b, int *c, int *d)
{
    printf("Nhap kich thuoc cua ma tran thu nhat:\n");
    printf("Nhap so hang a = ");
    scanf("%d", a);
    printf("Nhap so cot b = ");
    scanf("%d", b);
    printf("Nhap kich thuoc cua ma tran thu hai:\n");
    printf("Nhap so hang c = ");
    scanf("%d", c);
    printf("Nhap so cot d = ");
    scanf("%d", d);
}
void NhapMaTran(int *ma_tran, int a, int b)
{
    int i;
    for (i = 0; i < a*b; i++)
    {
        printf("Nhap phan tu [%d][%d]:\t", i/b, i%b);
        fflush(stdin);
        scanf("%d",&ma_tran[i]);
    }
}
void CongMaTran()
{
    int a, b, c, d;
    NhapKichThuocMaTran(&a, &b, &c, &d);
    if (!(a == c && b == d))
    {
        printf("Ban da nhap kich thuoc khong hop le cho viec cong 2 ma tran\n");
        printf("Ban co muon nhap lai khong? Y/N\n");
        char ch;
        ch = getch();
        if (ch == 'n' || ch == 'N')
            exit(1);
        else if (ch == 'y' || ch == 'Y')
        {
            system("cls");
            CongMaTran();
        }
    }
    int *ma_tran_1 = new int [a*b];
    printf("Nhap ma tran 1 kich thuoc %d x %d\n", a, b);
    NhapMaTran(ma_tran_1, a, b);
    int *ma_tran_2 = new int [c*d];
    printf("Nhap ma tran 2 kich thuoc %d x %d\n", c, d);
    NhapMaTran(ma_tran_2, a, b);
    int *ma_tran_result = new int [a*b];
    int i;
    for (i = 0; i < a*b; i++)
        ma_tran_result[i] = ma_tran_1[i] + ma_tran_2[i];
    system("cls");
    printf("Cong hai ma tran:\n\n");
    InMaTran(ma_tran_1, a, b);
    printf("\n + \n\n");
    InMaTran(ma_tran_2, c, d);
    printf("\n = \n\n");
    InMaTran(ma_tran_result, a, b);
    delete[] ma_tran_1;
    ma_tran_1 = NULL;
    delete[] ma_tran_2;
    ma_tran_2 = NULL;
    delete[] ma_tran_result;
    ma_tran_result = NULL;
    printf("\nDa cong xong 2 ma tran\n");
    getch();
}
void NhanMaTran()
{
    int a, b, c, d;
    NhapKichThuocMaTran(&a, &b, &c, &d);
    if ((b != c) && (a != d))
    {
        printf("Ban da nhap kich thuoc khong hop le cho viec nhan 2 ma tran\n");
        printf("Ban co muon nhap lai khong? Y/N\n");
        char ch;
        ch = getch();
        if (ch == 'n' || ch == 'N')
            exit(1);
        else if (ch == 'y' || ch == 'Y')
        {
            system("cls");
            NhanMaTran();
        }
    }
    if ((a == d) && (b != c))
    {
        int tmp = 0;
        tmp = a;
        a = c;
        c = tmp;
        tmp = b;
        b = d;
        d = tmp;
    }
    int *ma_tran_1 = new int [a*b];
    printf("Nhap ma tran 2 kich thuoc %d x %d\n", a, b);
    NhapMaTran(ma_tran_1, a, b);
    int *ma_tran_2 = new int [c*d];
    printf("Nhap ma tran 1 kich thuoc %d x %d\n", c, d);
    NhapMaTran(ma_tran_2, c, d);
    int *ma_tran_result = new int [a*d];
    int i, j;
    for (i = 0; i < a; i++)
        for (j = 0; j < d; j++)
        {
            ma_tran_result[i * d + j] = 0;
            int m = 0;
            while (m < b)
            {
                ma_tran_result[i * d + j] += (ma_tran_1[i * b + m] * ma_tran_2[m * d + j]);
                m++;
            }
        }
    system("cls");
    printf("Nhan hai ma tran:\n\n");
    InMaTran(ma_tran_1, a, b);
    printf("\n * \n\n");
    InMaTran(ma_tran_2, c, d);
    printf("\n = \n\n");
    InMaTran(ma_tran_result, a, d);
    delete[] ma_tran_1;
    ma_tran_1 = NULL;
    delete[] ma_tran_2;
    ma_tran_2 = NULL;
    delete[] ma_tran_result;
    ma_tran_result = NULL;
    printf("\nDa nhan xong 2 ma tran\n");
    getch();
}
void InMaTran(int *ma_tran, int a, int b)
{
    int i;
    for (i = 0; i < a*b; i++)
    {
        printf("%d", ma_tran[i]);
        if ((i + 1)%b == 0)
            printf("\n");
        else printf("\t");
    }
}
void TinhDinhThuc()
{
    int a;
    printf("Nhap cap cua ma tran vuong can tinh dinh thuc: ");
    fflush(stdin);
    scanf("%d", &a);
    int *ma_tran_1 = new int [a*a];
    printf("Nhap ma tran kich thuoc %d x %d de tinh dinh thuc\n", a, a);
    NhapMaTran(ma_tran_1, a, a);
    system("cls");
    printf("\n\nMa tran ban vua nhap la:\n");
    InMaTran(ma_tran_1, a, a);
    printf("\n\n");
    if (a == 1)
        printf("Dinh thuc cua ma tran tren la: %d", ma_tran_1[0]);
    else if (a == 2)
        printf("Dinh thuc cua ma tran tren la: %d", ma_tran_1[0] * ma_tran_1[3] - ma_tran_1[1] * ma_tran_1[2]);
    else if (a > 2)
    {
        int tong = DinhThucDeQuy(ma_tran_1, a);
        delete[] ma_tran_1;
        ma_tran_1 = NULL;
        printf("\nDinh thuc cua ma tran tren la: %d", tong);
    }
    getch();
}
int *TaoMaTranCon(int *ma_tran_1, int a, int m) // Tao ma tran moi, bo hang m va cot 0 di
{
    int i, j;
    int *ma_tran_2 = new int [(a-1) * (a-1)];
    for (i = 0; i < a; i++)
        for (j = 0; j < a-1; j++)
            if (ma_tran_1 [i*a + j] != ma_tran_1 [m*a + j])
            {
                if (i < m)
                    ma_tran_2 [i*(a-1) + j] = ma_tran_1 [i*a + j];
                else if (i > m)
                    ma_tran_2 [(i-1)*(a-1) + j] = ma_tran_1 [i*a + j];
            }
    return ma_tran_2;
}
int DinhThucDeQuy(int *ma_tran_1, int a)
{
    if (a == 3)
        return (ma_tran_1[0]*ma_tran_1[4]*ma_tran_1[8] + ma_tran_1[1]*ma_tran_1[5]*ma_tran_1[6] + ma_tran_1[2]*ma_tran_1[3]*ma_tran_1[7] - ma_tran_1[2]*ma_tran_1[4]*ma_tran_1[6] - ma_tran_1[1]*ma_tran_1[3]*ma_tran_1[8] - ma_tran_1[0]*ma_tran_1[5]*ma_tran_1[7]);
    else
    {
        int i;
        int tong = 0;
        for (i = 0; i < a; i++)
        {
            int *ma_tran_2 = TaoMaTranCon(ma_tran_1, a, i);
            if (a % 2 == 0)
                tong += pow(-1, i+1) * ma_tran_1[i * a + a-1] * DinhThucDeQuy(ma_tran_2, a-1);
            else
                tong += pow(-1, i) * ma_tran_1[i * a + a-1] * DinhThucDeQuy(ma_tran_2, a-1);
            delete[] ma_tran_2;
            ma_tran_2 = NULL;
        }
        return tong;
    }
}
