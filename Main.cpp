#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

class root_using; // объявление класса заранее

class root // система для рут-пользователя
{
	private:
		string password;
	//	string name;
	public:
		friend root_using; // дружный класс администрирования
	string getpassword ()
	{
		return this->password;
	}		
/*	void defsetpassword ()
	{
		this->password = "qwerty";
	} */
	void set_password (string p)
	{
		this->password = p;
		ofstream root ("root.txt");
		root << "admin " << this->password;
	}
	
};

class root_using 
{
	private:
		string newpassword;
	public:
		void showTurn ()
		{
			string a, b, c;
			ifstream lamps ("Lamps.txt");
			getline (lamps, a);
			cout << "********************************************************"<< endl;
			cout << "|               " << a << "                     |" << endl;
			lamps.close();
			ifstream frozen ("Frozen.txt");
			getline (frozen, b);
			cout << "|               " << b << "                     |" << endl;
			frozen.close();
			ifstream frost ("Frost.txt");
			getline (frost, c);
			cout << "|               " << c << "                     |" << endl;
			cout << "********************************************************"<< endl;
			frost.close();
		}
		void changeElements ()
		{
			int a;
			cout << "Введите номер элемента, который вы хотите изменить? (1 - Lamps, 2 - Frozen, 3 -NoFrost)";
			cin >> a;
			switch (a)
			{
				case 1:
					{
						ifstream lamps ("Lamps.txt");
						string str;
						getline (lamps, str);
						lamps.close();
						if (str == "Lamps = 0")
						{
							ofstream lamp ("Lamps.txt");
							cout << "Система улучшенного освещения включена." << endl;
							lamp << "Lamps = 1";
							lamp.close();
						}
						
						if (str == "Lamps = 1")
						{
							fstream lamp ("Lamps.txt");
							cout << "Система улучшенного освещения отключена." << endl;
							lamp << "Lamps = 0";
							lamp.close();
						}
				break;
				}
				case 2:
					{
						ifstream frozen ("Frozen.txt");
						string b;
						getline (frozen, b);
						frozen.close();
						if (b == "FrozenCam = 0")
						{
							ofstream froz ("Frozen.txt");
							cout << "Система улучшенной заморозки включена." << endl;
							froz << "FrozenCam = 1";
							froz.close();
						}
						if (b == "FrozenCam = 1")
						{
							ofstream froz ("Frozen.txt");
							cout << "Система улучшенной заморозки отключена." << endl;
							froz << "FrozenCam = 0";
							froz.close();
						}
					break;	
					}
			case 3:
				{
					string c;
					ifstream frost ("Frost.txt");
					getline (frost, c);
					frost.close();
					if (c == "NoFrost = 0")
					{
						ofstream fros ("Frost.txt");
						cout << "Система NoFrost включена." << endl;
						fros << "NoFrost = 1";
						fros.close();
					}
					if (c == "NoFrost = 1")
					{
						fstream fros ("Frost.txt");
						cout << "Система NoFrost отключена." << endl;
						fros << "NoFrost = 0";
						fros.close();
					}
					break;
				}
				default:
					{
						cout << "Ошибка в вводе значения. Повторите ещё раз. " << endl;
					}
			}
		}
		void setnewpassword (string z)
		{
			this->newpassword = z;
		}
		void togetnewpassword (root &obj)
		{
			obj.set_password(this->newpassword);
		}
};




class account // система основа, а также основа для классического юзера
{
	private:
		string password;
		string username;
	public:
		account ()
		{
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Здравствуйте, если у вас есть аккаунт, то введите 1, если у вас нету аккаунта, но вы хотите его зарегистровать, то введите 2, если хотите покинуть систему, то введите что-угодно: ";
			
		}
		void registration ()
		{
			string newusername;
			string newpassword;
			cout << "Гость, введите своё имя: ";
			cin >> newusername;
			this->username = newusername;
			cout << "Гость, введите новый пароль: ";
			cin >> newpassword;
			this->password = newpassword;
		}
		string getregistration_username ()
		{
			return this->username;
		}
		string getregistration_password ()
		{
			return this->password;
		}
};


class Lampa;               // объевление класса Лампа заранее
class FrozenCamera;            // объевление класса FrozenCamera заранее
class NoFrostSys;              // объевление класса NoFrostSys заранее



class user_using // система обычного юзера
{
	private:
		bool stateLamp;
		bool stateFrozenCam;
		bool stateNoFrost;
		
	public:
		friend Lampa;
		friend FrozenCamera;
		friend NoFrostSys;
		////////////////////////////////////////////////
		 bool set_state_Lamp (bool s)
		 {
		 	this->stateLamp = s;
		 }
		 //////////////////////////////////////////////
		 bool set_state_FrozenCam (bool s)
		 {
		 	this->stateFrozenCam = s;
		 }
		 ///////////////////////////////////////////////
		 bool set_state_NoFrost (bool s)
		 {
		 	this->stateFrozenCam = s;
		 }
		 ///////////////////////////////////////////////
		 void OffSystem (char i)
		 {
		 	
		 	string lampoff = "Lamps = 0", frozenoff = "FrozenCam = 0", frostoff = "NoFrost = 0";
		 	int num;
		 	if (i == 'Y')
		 	{
		 		cout << "Укажите систему, которую вы хотите отключить. (1 - освещение; 2 - заморозка; 3 - NoFrost) ";
		 		cin >> num;
				 switch (num)
				 {
				 	case 1:
				 		{
				 			ifstream lamps ("Lamps.txt");
				 			string str;
				 			getline (lamps, str);
				 			if (str == "Lamps = 0")
				 			{
				 				cout << "Система отключена до использования пользователем." << endl;
				 				break;
							}
							lamps.close();
							ofstream lamp ("Lamps.txt");
				 			cout << "Система улучшенного освещения отключена." << endl;
				 			this->stateLamp = 0;
				 			lamp << lampoff; 
				 			lamp.close();
				 			break;
						 }
					case 2:
						{
							ifstream frozen ("Frozen.txt");
							string str;
							getline (frozen, str);
							if (str == "FrozenCam = 0")
							{
								cout << "Система отключена до использования пользователем. " << endl;
								break;
							}
							frozen.close();
							ofstream froz ("Frozen.txt");
							cout << "Система улучшенной заморозки отключена. " << endl;
							this->stateFrozenCam = 0;
							froz << frozenoff;
							froz.close();
							break;
						}
					case 3:
						{
							ifstream frost ("Frost.txt");
							string str;
							getline (frost, str);
							if (str == "NoFrost = 0")
							{
								cout << "Система отключена до использования пользователем. " << endl;
								break;
							}
							frost.close();
							ofstream fros ("Frost.txt");
							cout << "Система NoFrost отключена. " << endl;
							this->stateNoFrost = 0;
							fros << frostoff;
							fros.close();
							break;
						}
					default:
						{
							cout << "Ошибка в вводе параметра." << endl;
						}
				 }	
			}
		 }
};


class Lampa // дружественный класс Лампа
{
	private:
		bool stateLampa;
	public:
	void turnLamps (char i)
		 {
		 	ofstream lamps ("Lamps.txt");
		 	string lampon = "Lamps = 1", lampoff = "Lamps = 0";
		 	if (i == 'Y')
		 	{
		 		cout << "Лампы с более лучшей освещаемостью включены."  << endl;
		 		this->stateLampa = 1;
		 		lamps << lampon;
		 		lamps.close ();
			}
			else
			{
				cout << "Лампы с более лучшей освещаемостью не задействованы."  << endl;
				this->stateLampa = 0;
				lamps << lampoff;
				lamps.close();
			}
		 }
		 void togetstateLampa (user_using &obj) // метод, который передаёт в объект значение влючения или отключения лампы
		 {
		 	obj.set_state_Lamp(this->stateLampa);
		 }
		 
};

class FrozenCamera
{
	private:
		bool stateFrozenCamera;
	public:
		void turnFrozenCam(char i)
		 {
		 	ofstream frozen ("Frozen.txt");
		 	string frozenon = "FrozenCam = 1", frozenoff = "FrozenCam = 0";
		 	if (i == 'Y')
		 	{
		 		cout << "Система улучшенной заморозки включена." << endl;
		 		this->stateFrozenCamera = 1;
		 		frozen << frozenon;
			}
			else
			{
				cout << "Система улучшенной заморозки не активирована." << endl;
				this->stateFrozenCamera = 0;
				frozen << frozenoff;
			}
			frozen.close();
		 }
		 void togetstateFrozenCam (user_using &obj)
		 {
		 	obj.set_state_FrozenCam(this->stateFrozenCamera);
		 }
		
};

class NoFrostSys
{
	private:
		bool stateNoFrostSys;
	public:
	void turnNoFrost (char i)
		 {
		 	ofstream frost ("Frost.txt");
		 	string froston = "NoFrost = 1", frostoff = "NoFrost = 0";
		 	if (i == 'Y')
		 	{
		 		cout << "Система NoFrost включена." << endl;
		 		this->stateNoFrostSys = 1;
		 		frost << froston;
			}
			else
			{
				cout << " Система NoFrost не активирована. " << endl;
				this->stateNoFrostSys = 0;
				frost << frostoff;
			}
			frost.close();
		 }
		void togetstateNoFrostSys (user_using &obj)
		{
			obj.set_state_NoFrost(this->stateNoFrostSys);
		}
};
	



int checker () // функция----/----проверка
{
	setlocale(LC_ALL, "Russian");
	char answer, a, buff [100];
	bool check = true;
	string username_in, password_in, result, adda = "admin";
	
	
	account user;
	root admin;
	//admin.defsetpassword();
	cin >> answer;
	if (answer == '2')
	{
		ofstream output ("user_base.txt", ios_base::app);
		user.registration();
		output << endl << user.getregistration_username() << " " << user.getregistration_password();
		output.close();
		return 3;
	}
	if (answer == '1')
	{
		while (answer != 'N')
		{
			cout << "Введите имя пользователя: ";
			cin >> username_in;
			cout << "Введите пароль: ";
			cin >> password_in;
			result = username_in + " " + password_in;
			ifstream input ("user_base.txt", ios_base::in);
			while (input)
			{
				string str;
				getline (input, str);
				if (str == result)
				{
					cout << "---------------------------------------------------------------------------------" << endl;
					cout << "Добро пожаловать, " << username_in << ". " << endl;;
					check = false;
					return 0;
				}
			
			}
			input.close();
			ifstream adda ("root.txt", ios_base::in);
			while (adda)
			{
				string str;
				getline (adda, str);
				if (str == result)
				{
					cout << "---------------------------------------------------------------------------------" << endl;
					cout << "Добро пожаловать администратор системы." << endl;
					check = false;
					return 1;
				}
			}
			adda.close();
			if (check)
			{
				cout << "Ошибка аутентификации. Хотите ли вы повторить попытку ввода данных? (Y/N) ";
				cin >> answer;
			}
			if (answer == 'N')
			{
				break;
			}	
			
		}
	}
	return 3;
	//account name;
}



int main ()
	{
		char answer;
		string pass;
		int i = 129;
		user_using One;
		root_using Two;
		root admin;
		Lampa LAM;
		FrozenCamera FRO;
		NoFrostSys NOF;
		do
		{
			switch (checker ())
		{
			case 0:
				{
					i = 0;
					break;
				}
			case 1:
				{
					i = 1;
					break;
				}
			case 3:
				{
					i = 3;
					break;
				}
			default:
				{
					cout << "---------------------------------------------------------------------------------" << endl;
					cout << "Можете покинуть программу." << endl;
					answer = 'N';
					break;
				}
		}
		
		if (i == 0)
		{
			
			cout << "Производится автоматическое открытие двери." << endl;
			cout << "Желаете ли вы включить лампы с более лучшей освещаемостью? (Y/N) ";
			cin >> answer;
			LAM.turnLamps(answer);
			LAM.togetstateLampa(One);
			cout << "Желаете ли вы включить систему более лучшей заморозки? (Y/N) ";
			cin >> answer;
			FRO.turnFrozenCam(answer);
			FRO.togetstateFrozenCam(One);
			cout << "Желаете ли вы включить систему NoFrost? (Y/N) ";
			cin >> answer;
			NOF.turnNoFrost(answer);
			NOF.togetstateNoFrostSys(One);
			do 
			{
				cout << "Желаете ли вы отключить некоторые системы? (Y/N) ";
				cin >> answer;
				One.OffSystem(answer);
			}
			while (answer != 'N');
			cout << "Производится автоматическое закрытие дверей." << endl;
			cout << "---------------------------------------------------------------------------------" << endl;
			cout << "Хотите ли вы перезайти в систему? (Y/N) ";
			cin >> answer;
		}
		
				if (i == 1)
				{
					
					do
					{
						cout << "Вы можете просмотреть состояние элементов холодильника (введите 1) или поменять пароль (введите 2), либо покинуть систему: ";
						cin >> answer;
						if (answer == '1')
						{
							Two.showTurn();
							while (answer != 'N')
							{
								cout << "Хотите ли вы изменить настройки элементов системы? (Y/N) " << endl;
								cin >> answer;
							if (answer == 'Y')
								{
									Two.changeElements();
								}
								else
								{
									break;
								}
							}
							 
						}
						if (answer == '2')
						{
							cout << "Введите новый пароль: ";
							cin >> pass;
							Two.setnewpassword(pass);
							Two.togetnewpassword(admin);
							cout << "Замена пароля успешна завершена. " << endl;
						}
						else 
						{
							break;
						}
					}
					while (answer != '1' | '2');
					cout << "Производится автоматическое закрытие дверей." << endl;
					cout << "---------------------------------------------------------------------------------" << endl;
					cout << "Хотите ли вы перезайти в систему? (Y/N) ";
					cin >> answer;	
				}
			if (i == 3)
			{
				break;
				}	
		}
		while (answer != 'N');
		cout << "Можете покинуть систему." << endl;
	}
