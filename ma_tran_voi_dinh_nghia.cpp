#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void CongMaTran();
void NhanMaTran();
void NhanMaTranVoiMotSo();


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
        printf("\n              3.Nhan ma tran voi 1 so");
        printf("\n        bam 1-3 de chon, phim khac de ket thuc: ");
        ch=getch();
        printf("\n\n");
        if (ch == '1')
            CongMaTran();
        else if (ch == '2')
            NhanMaTran();
        else if (ch == '3')
            NhanMaTranVoiMotSo();
        else
        {
            printf("\n ARE YOU SURE ? Y/..");
            fflush(stdin);
            ch=getch();
            if (ch=='y'||ch=='Y')
                break;
        }
    }
    return 0;
}


struct matrix
{
    int a, b;
    float **ma_tran;
    void InMaTran()
    {
        int i, j;
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < b; j++)
                printf("%.2f\t", ma_tran[i][j]);
            printf("\n");
        }
    }
    void CapBoNho()
    {
        ma_tran = new float *[a];
        int i;
        for (i = 0; i < a; i++)
            ma_tran[i] = new float [b];
    }
    void NhapMaTran()
    {
        CapBoNho();
        int i, j;
        for (i = 0; i < a; i++)
            for (j = 0; j < b; j++)
            {
                printf("Nhap phan tu [%d][%d]: ", i, j);
                fflush(stdin);
                scanf("%f", &ma_tran[i][j]);
            }
    }
    void ThuBoNho()
    {
        int i;
        for (i = 0; i < a; i++)
            {
                delete[] ma_tran[i];
                ma_tran[i] = NULL;
            }
        delete[] ma_tran;
        ma_tran = NULL;
    }
};
matrix operator + (matrix MT_1, matrix MT_2)
{
    int i, j;
    matrix MT_result;
    MT_result.a = MT_1.a;
    MT_result.b = MT_1.b;
    MT_result.CapBoNho();
    for (i = 0; i < MT_1.a; i++)
        for (j = 0; j < MT_1.b; j++)
        MT_result.ma_tran[i][j] = MT_1.ma_tran[i][j] + MT_2.ma_tran[i][j];
    return MT_result;
}
matrix operator * (matrix MT_1, matrix MT_2)
{
    int i, j;
    matrix MT_result;
    MT_result.a = MT_1.a;
    MT_result.b = MT_2.b;
    MT_result.CapBoNho();
    for (i = 0; i < MT_1.a; i++)
        for (j = 0; j < MT_2.b; j++)
        {
            int m = 0;
            MT_result.ma_tran[i][j] = 0;
            while (m < MT_1.b)
                {
                    MT_result.ma_tran[i][j] += MT_1.ma_tran[i][m] * MT_2.ma_tran[m][j];
                    m++;
                }
        }
    return MT_result;
}
matrix operator * (matrix MT, float c)
{
    int i, j;
    matrix MT_result;
    MT_result.a = MT.a;
    MT_result.b = MT.b;
    MT_result.CapBoNho();
    for (i = 0; i < MT.a; i++)
        for (j = 0; j < MT.b; j++)
            MT_result.ma_tran[i][j] = c * MT.ma_tran[i][j];
    return MT_result;
}
void NhapKichThuocMaTran(matrix &MT_1, matrix &MT_2)
{
    printf("Nhap kich thuoc cua ma tran thu nhat :\n");
    printf("Nhap so hang: ");
    scanf("%d", &MT_1.a);
    printf("Nhap so cot: ");
    scanf("%d", &MT_1.b);
    printf("Nhap kich thuoc cua ma tran thu hai :\n");
    printf("Nhap so hang: ");
    scanf("%d", &MT_2.a);
    printf("Nhap so cot: ");
    scanf("%d", &MT_2.b);
}


void CongMaTran()
{
    matrix MT_1, MT_2, MT_3;
    NhapKichThuocMaTran(MT_1, MT_2);
    if ((MT_1.a != MT_2.a) || (MT_1.b != MT_2.b))
    {
        printf("\nBan da nhap kich thuoc khong phu hop de cong ma tran. Ban co muon nhap lai? Y/N");
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
    system("cls");
    printf("Nhap du lieu ma tran thu nhat (%d x %d)\n", MT_1.a, MT_1.b);
    MT_1.NhapMaTran();
    printf("Nhap du lieu ma tran thu hai (%d x %d)\n", MT_2.a, MT_2.b);
    MT_2.NhapMaTran();
    printf("\n\n");
    MT_1.InMaTran();
    printf("\n + \n\n");
    MT_2.InMaTran();
    printf("\n = \n\n");
    MT_3 = MT_1 + MT_2;
    MT_3.InMaTran();
    MT_1.ThuBoNho();
    MT_2.ThuBoNho();
    MT_3.ThuBoNho();
    printf("\n\nDa cong xong 2 ma tran\n");
    getch();
}
void NhanMaTran()
{
    matrix MT_1, MT_2, MT_3;
    NhapKichThuocMaTran(MT_1, MT_2);
    if (MT_1.b != MT_2.a)
    {
        printf("\nBan da nhap kich thuoc khong phu hop de nhan ma tran. Ban co muon nhap lai? Y/N");
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
    system("cls");
    printf("Nhap du lieu ma tran thu nhat (%d x %d)\n", MT_1.a, MT_1.b);
    MT_1.NhapMaTran();
    printf("Nhap du lieu ma tran thu hai (%d x %d)\n", MT_2.a, MT_2.b);
    MT_2.NhapMaTran();
    printf("\n\n");
    MT_1.InMaTran();
    printf("\n * \n\n");
    MT_2.InMaTran();
    printf("\n = \n\n");
    MT_3 = MT_1 * MT_2;
    MT_3.InMaTran();
    MT_1.ThuBoNho();
    MT_2.ThuBoNho();
    MT_3.ThuBoNho();
    printf("\n\nDa nhan xong ma tran\n");
    getch();
}
void NhanMaTranVoiMotSo()
{
    matrix MT, MT_2;
    float c;
    printf("Nhap kich thuoc ma tran muon nhan\n");
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &MT.a);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &MT.b);
    printf("Nhap du lieu ma tran (%d x %d)\n", MT.a, MT.b);
    MT.NhapMaTran();
    printf("\n\nNhap so muon nhan voi ma tran: ");
    scanf("%f", &c);
    printf("\n\n");
    MT.InMaTran();
    printf("\n          * \n\n       %.2f", c);
    printf("\n\n          = \n\n");
    MT_2 = MT * c;
    MT_2.InMaTran();
    MT.ThuBoNho();
    MT_2.ThuBoNho();
    printf("\n\nDa nhan xong!!!\n");
    getch();
}
