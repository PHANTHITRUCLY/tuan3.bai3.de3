#include <iostream>
using namespace std;
#include <fstream>
struct Ngay{
	int d, m, y;
};

class Nhanvien{
	public:
		bool loai;
		char Ten[30];
		bool Gioitinh;
		Ngay Ngayvaolam;
		const float Hesoluong = 1.5;
		int Socon;
		const int luongcb = 1120000;
		int Tinhngay(int d, int m, int y) {
        if (m < 3) {
            y--;
            m += 12;
        }
        return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
    }
		int Tienluong();
		int Trocap();
		int TienthuongNV(){
			int namlamviec = (Tinhngay(11,1,2019) - Tinhngay(Ngayvaolam.d,Ngayvaolam.m,Ngayvaolam.y))/365;
			return (namlamviec * 1000000);
		}
		
};

class NhanvienVP : public Nhanvien{
	public:
		int Songayvang;
		const int Dinhmucvang = 4;
		const int Dinhmucphat = 50000;
		
		void NhapNVVP(){
		cout<<endl<<"Nhap ten: ";
		fflush(stdin);
		cin.getline(Ten,30);
		cout<<endl<<"Nhap gioi tinh ( 1 la nu, 0 la nam): ";
		cin>>Gioitinh;
		cout<<endl<<"Nhap ngay vao lam: ";
		cin>>Ngayvaolam.d;
		cout<<"/";
		cin>>Ngayvaolam.m;
		cout<<"/";
		cin>>Ngayvaolam.y;
		cout<<endl<<"Nhap so con: ";
		cin>>Socon;	
		cout<<endl<<"Nhap so ngay vang: ";
		cin>>Songayvang;
	}

		int Tienphat(){
			if(Songayvang > Dinhmucvang) return Songayvang * Dinhmucphat;
			else return 0;
		}
		int Trocap(){
			if(Gioitinh == 1 ) return 200000 * Socon * 1.5;
			else return 200000 * Socon;
		}
		int Tienluong(){
			int phat = Tienphat();
			return luongcb * Hesoluong - phat;
		}
		
		
		

	void XuatNVVP(){
		cout<<endl<<"Ten: "<<Ten;
		if(Gioitinh == 1) cout<<endl<<"Gioitinh: Nu";
		else cout<<endl<<"Gioitinh: Nam";
		cout<<endl<<"Ngay vao lam: "<<Ngayvaolam.d<<"/"<<Ngayvaolam.m<<"/"<<Ngayvaolam.y;
		cout<<endl<<"So con: "<<Socon;
		cout<<endl<<"So ngay vang: "<<Songayvang;
		int thuong = TienthuongNV();
		int phat = Tienphat();
		int luong = Tienluong();
		int trocap = Trocap();
		cout<<endl<<"Tien thuong nhan vien: "<<thuong;
		cout<<endl<<"Tien phat: "<<phat;
		cout<<endl<<"Tien tro cap: "<<trocap;
		cout<<endl<<"Tien luong: "<<luong;
}

		
};

class NhanvienSX : public Nhanvien{
	public:
		int Sosp;
		const int Dinhmucsp = 10;
		const int Dongiasp = 150000;
		
		void NhapNVSX(){
		cout<<endl<<"Nhap ten: ";
		fflush(stdin);
		cin.getline(Ten,30);
		cout<<endl<<"Nhap gioi tinh ( 1 la nu, 0 la nam): ";
		cin>>Gioitinh;
		cout<<endl<<"Nhap ngay vao lam: ";
		cin>>Ngayvaolam.d;
		cout<<"/";
		cin>>Ngayvaolam.m;
		cout<<"/";
		cin>>Ngayvaolam.y;
		cout<<endl<<"Nhap so con: ";
		cin>>Socon;	
		cout<<endl<<"Nhap so sp: ";
		cin>>Sosp;
	}	
		
		int Tienthuong(){
			if(Sosp > Dinhmucsp) return (Sosp - Dinhmucsp) * Dongiasp * 0.03;
			else return 0;
		}
		int Trocap(){
			return Socon * 120000;
		}
		int Tienluong(){
			int thuong = Tienthuong();
			return (Sosp * Dongiasp) + thuong;
		}
		
		void XuatNVSX(){
		cout<<endl<<"Ten: "<<Ten;
		if(Gioitinh == 1) cout<<endl<<"Gioitinh: Nu";
		else cout<<endl<<"Gioitinh: Nam";
		cout<<endl<<"Ngay vao lam: "<<Ngayvaolam.d<<"/"<<Ngayvaolam.m<<"/"<<Ngayvaolam.y;
		cout<<endl<<"So con: "<<Socon;
		cout<<endl<<"So san pham: "<<Sosp;
		int thuongnv = TienthuongNV();
		int thuong = Tienthuong();
		int luong = Tienluong();
		int trocap = Trocap();
		cout<<endl<<"Tien thuong nhan vien: ";
		cout<<endl<<"Tien thuong: "<<thuong;
		cout<<endl<<"Tien tro cap: "<<trocap;
		cout<<endl<<"Tien luong: "<<luong;
		
}

		
};


void NhapmangNV(Nhanvien a[], NhanvienVP c[], NhanvienSX d[], int n)
{
	int vp = 0, sx = 0;
	
	for(int i = 0; i < n; i++)
		{
			cout<<endl<<"Nhap loai nhan vien (1 la vp, 0 la sx): ";
			cin>>a[i].loai;
			if(a[i].loai == 1){
			c[vp].NhapNVVP();
			vp++;
			}
			else{
				d[sx].NhapNVSX();
				sx++;
			}
			
		}
}

void DocmangNV(Nhanvien a[], NhanvienVP c[], NhanvienSX d[], int &n){
	int vp = 0,sx = 0;
	fstream doc;
	doc.open("nv.txt",ios::in);
	doc>>n;
	for(int i = 0; i < n; i++){
		doc>>a[i].loai;
		if(a[i].loai == 1){
			doc>>c[vp].Gioitinh;
			doc>>c[vp].Ngayvaolam.d;
			doc>>c[vp].Ngayvaolam.m;
			doc>>c[vp].Ngayvaolam.y;
			doc>>c[vp].Socon;
			doc>>c[vp].Songayvang;
			doc.getline(c[vp].Ten,30);
			vp++;
		}
		else{
			doc>>d[sx].Gioitinh;
			doc>>d[sx].Ngayvaolam.d;
			doc>>d[sx].Ngayvaolam.m;
			doc>>d[sx].Ngayvaolam.y;
			doc>>d[sx].Socon;
			doc>>d[sx].Sosp;
			doc.getline(d[sx].Ten,30);
			sx++;
		}
	}
	doc.close();
	
}


void XuatmangNV(Nhanvien a[], NhanvienVP c[], NhanvienSX d[], int n){
	int vp = 0, sx = 0;	
	for(int i = 0; i < n; i++)
		{
			if(a[i].loai == 1){
			cout<<endl<<"Nhan vien VP: ";
			c[vp].XuatNVVP();
			vp++;
			cout<<endl;
			}
			else{
				cout<<endl<<"Nhan vien SX: ";
				d[sx].XuatNVSX();
				sx++;
				cout<<endl;
			}
			
		}
}


int main(){
	Nhanvien a[100];
	NhanvienVP c[50];
	NhanvienSX d[50];
	int n;
	DocmangNV(a,c,d,n);
	XuatmangNV(a,c,d,n);
}
