#pragma once
#include"SFML/Graphics.hpp"
#include <vector>
#include <string>
#include"Banker.h"
using namespace std;
#define MAX_OBJECTS 5
#define MAX_PROPERTIES 4
#define MAX_THREAD 8 
class banker_objects
{
public:
	int nums_processes;
	int nums_properties;
	void get_nums_processes_properties(int n, int m)
	{
		nums_processes = n;
		nums_properties = m;
	}

	banker_objects(int n, int m)
	{
		get_nums_processes_properties(n, m);
	}

	void init_BK_objects(int width, int height)
	{
		int half_width = width / 2;
		int half_height = height / 2;

		BK_objects[0].setSize(sf::Vector2f(half_width, 100));
		sf::Vector2f available_origin(BK_objects[0].getSize().x / 2, BK_objects[0].getSize().y / 2);
		BK_objects[0].setOrigin(available_origin);
		BK_objects[0].setPosition(sf::Vector2f(half_width, 125));
		BK_objects[0].setFillColor(sf::Color::White);//0 la available

		BK_objects[1].setSize(sf::Vector2f(100, 250));
		sf::Vector2f request_origin(BK_objects[1].getSize().x / 2, BK_objects[1].getSize().y / 2);
		BK_objects[1].setOrigin(request_origin);
		BK_objects[1].setPosition(sf::Vector2f(100, half_height));
		BK_objects[1].setFillColor(sf::Color::White);//1 la need

		BK_objects[2].setSize(sf::Vector2f(100, 250));
		sf::Vector2f need_origin(BK_objects[2].getSize().x / 2, BK_objects[2].getSize().y / 2);
		BK_objects[2].setOrigin(need_origin);
		BK_objects[2].setPosition(sf::Vector2f(width - 75, half_height));
		BK_objects[2].setFillColor(sf::Color::White);//2 la request

		BK_objects[3].setSize(sf::Vector2f(100, 250));
		sf::Vector2f allocation_origin(BK_objects[3].getSize().x / 2, BK_objects[3].getSize().y / 2);
		BK_objects[3].setOrigin(allocation_origin);
		BK_objects[3].setPosition(sf::Vector2f(width - 265, half_height));//bk_object[2] cach man hinh ben phai tong cong la 150,ma bk_objects[3] origin_x la 50 nen width+50-200 = cach man hinh 150 = bk2
		BK_objects[3].setFillColor(sf::Color::White);//3 la allocation moi nguoi

		BK_objects[4].setSize(sf::Vector2f(half_width, 200));
		sf::Vector2f all_origin(BK_objects[4].getSize().x / 2, BK_objects[4].getSize().y / 2);
		BK_objects[4].setOrigin(all_origin);
		BK_objects[4].setPosition(sf::Vector2f(half_width, height - all_origin.y - 50));
		BK_objects[4].setFillColor(sf::Color::White);//4 la allocation cua tat ca mn

	}

	void init_BK_objects_names(int character_size, sf::Color color)
	{
		BK_objects_names[0].setString("AVAILABLE");
		BK_objects_names[1].setString("REQUEST");
		BK_objects_names[2].setString("NEED");
		BK_objects_names[3].setString("MAX");
		BK_objects_names[4].setString("ALOCATION");

		for (int i = 0; i < MAX_OBJECTS; i++)
		{
			BK_objects_names[i].setFont(font);
			BK_objects_names[i].setCharacterSize(character_size);
			BK_objects_names[i].setFillColor(color);
			sf::Vector2f pos(BK_objects[i].getPosition().x, BK_objects[i].getPosition().y - BK_objects[i].getSize().y / 2 + BK_objects_names[i].getGlobalBounds().height);
			BK_objects_names[i].setPosition(pos);
			sf::Vector2f origin(BK_objects_names[i].getGlobalBounds().width / 2, (BK_objects_names[i].getGlobalBounds().height / 2));
			BK_objects_names[i].setOrigin(origin);
		}
	}

	void init_processes_names(sf::Color color, int size)
	{
		sf::Vector2f pos(BK_objects_names[4].getPosition().x - BK_objects[4].getSize().x / 2, BK_objects_names[4].getPosition().y + 20);
		int move_x = BK_objects[4].getSize().x / (nums_processes + 1);
		int temp = move_x;
		for (int i = 0; i < nums_processes; i++)
		{
			process_names[i].setFont(font);
			process_names[i].setFillColor(color);
			process_names[i].setCharacterSize(size);
			string P_name = "P" + to_string(i);
			process_names[i].setString(P_name);
			pos.x += move_x;
			process_names[i].setPosition(pos.x, pos.y);
			sf::Vector2f origin(process_names[i].getGlobalBounds().width / 2, process_names[i].getGlobalBounds().height / 2);
			process_names[i].setOrigin(origin);
		}
	}

	void init_resource(int char_size, sf::Color color)
	{
		char name_of_resource = 'A';
		for (int i = 0; i < nums_properties; i++)
		{
			resource_names[i].setFont(font);
			resource_names[i].setCharacterSize(char_size);
			resource_names[i].setFillColor(color);
			resource_names[i].setString(name_of_resource++);
		}
	}

	void get_available_properties(int char_size, sf::Color color, v<int> Available)
	{
		int Avail_size = Available.size();
		for (int i = 0; i < Avail_size; i++)
		{
			available_properties[i].setFont(font);
			available_properties[i].setString(to_string(Available[i]));
			available_properties[i].setCharacterSize(char_size);
			available_properties[i].setFillColor(color);
		}
	}

	void get_allocation_properties(int char_size, sf::Color color, v<v<int>> Allocation)
	{
		int size = Allocation.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < nums_properties; j++)
			{
				allocation_properties[i][j].setFont(font);
				allocation_properties[i][j].setString(to_string(Allocation[i][j]));
				allocation_properties[i][j].setCharacterSize(char_size);
				allocation_properties[i][j].setFillColor(color);

			}
		}
	}

	void set_Avail_pos()
	{
		sf::Vector2f pos(BK_objects[0].getPosition().x - BK_objects[0].getSize().x / 2, BK_objects[0].getPosition().y);
		int move_x = BK_objects[0].getSize().x / 4;
		for (int i = 0; i < nums_properties; i++)
		{
			pos.x += move_x;
			sf::Vector2f origin(available_properties[i].getGlobalBounds().width / 2, available_properties[i].getGlobalBounds().height / 2);
			available_properties[i].setOrigin(origin);
			available_properties[i].setPosition(pos);
		}
	}

	void set_Allocation_pos()
	{
		sf::Vector2f pos(BK_objects[4].getPosition().x - BK_objects[4].getSize().x / 2, BK_objects[4].getPosition().y - BK_objects[4].getSize().y / 2);
		sf::Vector2f move(BK_objects[4].getSize().x / (nums_processes + 1), BK_objects[4].getSize().y / (nums_properties + 1));
		for (int i = 0; i < nums_processes; i++)
		{
			pos.x += move.x;
			for (int j = 0; j < nums_properties; j++)
			{
				pos.y += move.y;
				sf::Vector2f orgin(allocation_properties[i][j].getGlobalBounds().width / 2, allocation_properties[i][j].getGlobalBounds().height / 2);
				allocation_properties[i][j].setOrigin(orgin);
				allocation_properties[i][j].setPosition(process_names[i].getPosition().x, pos.y);

			}
			pos.y -= BK_objects[4].getSize().y - move.y;
		}
	}

	void init_Max_Request_Need(int char_size, sf::Color color)
	{
		for (int i = 0; i < nums_properties; i++)
		{
			max_properties[i].setFont(font);
			max_properties[i].setCharacterSize(char_size);
			max_properties[i].setFillColor(color);
			max_properties[i].setString("None");

			request_properties[i].setFont(font);
			request_properties[i].setCharacterSize(char_size);
			request_properties[i].setFillColor(color);
			request_properties[i].setString("None");

			need_properties[i].setFont(font);
			need_properties[i].setCharacterSize(char_size);
			need_properties[i].setFillColor(color);
			need_properties[i].setString("None");
		}
	}

	void done_request_max_need()
	{
		for (int i = 0; i < nums_properties; i++)
		{
			max_properties[i].setString("None");
			request_properties[i].setString("None");
			need_properties[i].setString("None");
		}
	}

	void get_Max(v<v<int>> Max, int index)// ham nay se duoc lien tuc thay doi theo gia tri Id hien tai
	{
		for (int j = 0; j < nums_properties; j++)
		{
			max_properties[j].setString(to_string(Max[index][j]));
		}
	}

	void get_Need(v<v<int>> Need, int index)// ham nay se duoc lien tuc thay doi theo gia tri index hay gia tri cua process hien tai dang chay-index la ID nha dau tien dinh lay index ma thay sai sai
	{
		for (int j = 0; j < nums_properties; j++)
		{
			need_properties[j].setString(to_string(Need[index][j]));
		}
	}
	int get_request_id_index(v<v<int>> Request, string id_request)//tra ve index hang cua request de nhan gia tri
	{
		int size_n = Request.size();
		if (size_n == 0) return 0;
		int size_m = Request[0].size();
		for (int i = 0; i < size_n; i++)
		{
			if (Request[i][size_m - 1] == stoi(id_request)) return i;
		}
		return -1;
	}
	void get_Request(v<v<int>> Request, string request_id)//truyen string ID vao vi request no bi erase lien tuc nen viec truyen index la khong the
	{
		int index = get_request_id_index(Request, request_id);
		if (index == -1) return;
		for (int j = 0; j < nums_properties; j++)
		{
			request_properties[j].setString(to_string(Request[index][j]));
		}
	}

	void get_Allocation(v<v<int>> Allocation, int index)
	{
		for (int j = 0; j < nums_properties; j++)
		{
			allocation_properties[index][j].setString(to_string(Allocation[index][j]));
		}
	}

	void get_Available(v<int> Avail)
	{
		for (int j = 0; j < nums_properties; j++)
		{
			available_properties[j].setString(to_string(Avail[j]));
		}
	}

	void get_all_properties_except_request(v<int> Avail, v<v<int>> Allocation, v<v<int>>Max, v<v<int>>Need, int i)
	{
		get_Available(Avail);
		get_Allocation(Allocation, i);
		get_Max(Max, i);
		get_Need(Need, i);
	}
	void set_Max_pos()
	{
		sf::Vector2f pos(BK_objects[3].getPosition().x, BK_objects[3].getPosition().y - BK_objects[3].getSize().y / 2);
		float move_y = BK_objects[3].getSize().y / (nums_properties + 1);
		for (int i = 0; i < nums_properties; i++)
		{
			pos.y += move_y;
			sf::Vector2f origin(max_properties[i].getGlobalBounds().width / 2, max_properties[i].getGlobalBounds().height / 2);
			max_properties[i].setOrigin(origin);
			max_properties[i].setPosition(pos);
		}
	}

	void set_Need_pos()
	{
		sf::Vector2f pos(BK_objects[2].getPosition().x, BK_objects[2].getPosition().y - BK_objects[2].getSize().y / 2);
		float move_y = BK_objects[2].getSize().y / (nums_properties + 1);
		for (int i = 0; i < nums_properties; i++)
		{
			pos.y += move_y;
			sf::Vector2f origin(need_properties[i].getGlobalBounds().width / 2, need_properties[i].getGlobalBounds().height / 2);
			need_properties[i].setOrigin(origin);
			need_properties[i].setPosition(pos);
		}
	}

	void set_Request_pos()
	{
		sf::Vector2f pos(BK_objects[1].getPosition().x, BK_objects[3].getPosition().y - BK_objects[1].getSize().y / 2);
		float move_y = BK_objects[1].getSize().y / (nums_properties + 1);
		for (int i = 0; i < nums_properties; i++)
		{
			pos.y += move_y;
			sf::Vector2f origin(max_properties[i].getGlobalBounds().width / 2, max_properties[i].getGlobalBounds().height / 2);
			request_properties[i].setOrigin(origin);
			request_properties[i].setPosition(pos);
		}
	}


	void init_banker_objects(int width, int height, int character_size, sf::Font font_from_file, sf::Color color, v<int> Available, v<v<int>> Allocation, v<v<int>>Max, v<v<int>>Request, v<v<int>>Need)
	{
		font = font_from_file;
		init_BK_objects(width, height);
		init_BK_objects_names(character_size, color);
		init_processes_names(color, character_size);
		init_resource(character_size, color);
		get_available_properties(character_size, color, Available);
		get_allocation_properties(character_size, color, Allocation);
		set_Avail_pos();
		set_Allocation_pos();
		init_Max_Request_Need(character_size, color);
		set_Request_pos();
		set_Need_pos();
		set_Max_pos();
		init_status();
	}

	void draw_objects(sf::RenderWindow& window)
	{
		for (int i = 0; i < MAX_OBJECTS; i++)
		{
			window.draw(BK_objects[i]);
			window.draw(BK_objects_names[i]);
		}
	}

	void draw_process_name(sf::RenderWindow& window)
	{
		for (int i = 0; i < nums_processes; i++)
		{
			window.draw(process_names[i]);
		}
	}

	void draw_resource(sf::RenderWindow& window)
	{
		sf::Vector2f available_pos(BK_objects_names[0].getPosition().x - BK_objects[0].getSize().x / 2, BK_objects[0].getPosition().y - BK_objects[0].getSize().y / 2 + BK_objects_names[0].getGlobalBounds().height + 20);
		int move_x = BK_objects[0].getSize().x / (nums_properties + 1);
		for (int j = 0; j < nums_properties; j++)
		{
			available_pos.x += move_x;
			sf::Vector2f origin(resource_names[j].getGlobalBounds().width / 2, resource_names[j].getGlobalBounds().height);
			resource_names[j].setOrigin(origin);
			resource_names[j].setPosition(available_pos);
			window.draw(resource_names[j]);
		}
		for (int i = 1; i < MAX_OBJECTS; i++)//hmm co cach nao lam cho no nhanh hon k ta de xong r co gi lam lai cho nay
		{
			int move_y = BK_objects[i].getSize().y / (nums_properties + 1);
			sf::Vector2f pos(BK_objects_names[i].getPosition().x - BK_objects[i].getSize().x / 2 + 5, BK_objects[i].getPosition().y - BK_objects[i].getSize().y / 2 + 5);
			for (int j = 0; j < nums_properties; j++)
			{
				pos.y += move_y;
				resource_names[j].setPosition(pos.x, pos.y);
				window.draw(resource_names[j]);
			}
		}
	}

	void draw_Available(sf::RenderWindow& window)
	{
		for (int i = 0; i < nums_properties; i++)
		{
			window.draw(available_properties[i]);
		}
	}

	void draw_Allocation(sf::RenderWindow& window)
	{
		for (int i = 0; i < nums_processes; i++)
		{
			for (int j = 0; j < nums_properties; j++)
			{
				window.draw(allocation_properties[i][j]);
			}
		}
	}

	void draw_Max_Request_Need(sf::RenderWindow& window)
	{
		for (int i = 0; i < nums_properties; i++)
		{
			window.draw(max_properties[i]);
			window.draw(need_properties[i]);
			window.draw(request_properties[i]);
		}
	}

	void draw_status(sf::RenderWindow& window)
	{
		window.draw(status_table);
		window.draw(status_name);
		window.draw(status);
	}
	void draw_all(sf::RenderWindow& window)//dung de ve tat ca moi thu
	{
		draw_objects(window);
		draw_process_name(window);
		draw_resource(window);
		draw_Available(window);
		draw_Allocation(window);
		draw_Max_Request_Need(window);
		draw_status(window);
	}

	void change_status(int state, int index)//can them 1 bien state o ham addrequest de hien thi trang thai: 1 la nhan request,0 la wait, -1 la reject request cai nay lay result cung duoc 
		//con bien state =2 thi la Process Running dung trong khuc chay safety a
	{
		switch (state)
		{
		case -1:
		{
			status.setString("Decline request");
			break;
		}
		case 0:
		{
			status.setString("Wait");
			break;
		}
		case 1://chap nhan request
		{
			status.setString("Accept request");
			break;
		}
		case 2:
		{
			string p_state = "Process " + to_string(index) + " is running";
			status.setString(p_state);
			break;
		}
		default:
		{
			status.setString("A Project From The ERROR Team");
			break;
		}
		}
		status.setOrigin(status.getGlobalBounds().width / 2, status.getGlobalBounds().height / 2);
	}

	void running_Process(int index)//truyen index cua P dang chay hay la vi tri hang cua process do 
	{
		process_names[index].setFillColor(sf::Color::Red);
		for (int i = 0; i < nums_properties; i++)
		{
			allocation_properties[index][i].setFillColor(sf::Color::Red);
		}
	}
	void Process_done(int index)//ham nay khi process chay xong thi ta doi mau lai mau den
	{
		process_names[index].setFillColor(sf::Color::Red);
		for (int i = 0; i < nums_properties; i++)
		{
			allocation_properties[index][i].setFillColor(sf::Color::Black);
		}
	}

	void all_done()//ham nay dung de xuat khi tat ca P da xong het
	{
		status.setString("All Done");
		status.setOrigin(status.getGlobalBounds().width / 2, status.getGlobalBounds().height / 2);
		for (int i = 0; i < nums_properties; i++)
		{
			max_properties[i].setString("Done");

			request_properties[i].setString("Done");

			need_properties[i].setString("Done");
		}
	}
	void request_done()
	{
		for (int i = 0; i < nums_properties; i++)
		{
			request_properties[i].setString("Done");
		}
	}
	void init_status()
	{
		status_table.setSize(sf::Vector2f(200.0, 100.0));
		status_table.setOrigin(100.0, 50.0);
		status_table.setFillColor(sf::Color::White);
		status_table.setPosition(BK_objects[0].getPosition().x + BK_objects[0].getSize().x/2 +150  , BK_objects[0].getPosition().y);

		status_name.setCharacterSize(15);
		status_name.setFillColor(sf::Color::Black);
		status_name.setString("Status");
		status_name.setFont(font);
		status_name.setOrigin(status_name.getGlobalBounds().width / 2, status_name.getGlobalBounds().height / 2);
		status_name.setPosition(status_table.getPosition().x, status_table.getPosition().y - status_table.getSize().y / 2 + status_name.getGlobalBounds().height);

		status.setCharacterSize(10);
		status.setFillColor(sf::Color::Black);
		status.setString("A Project From The ERROR Team");
		status.setFont(font);
		status.setOrigin(status.getGlobalBounds().width / 2, status.getGlobalBounds().height / 2);
		status.setPosition(status_table.getPosition().x, status_table.getPosition().y);
	}


	sf::Vector2f get_bk_objects_request_pos()
	{
		return BK_objects[1].getPosition();
	}

	int  get_status_table_pos_x()//dung de lay vi tri status table de ve process, x nam o chinh giua cua status table
	{
		return status_table.getPosition().x;
	}
	
	int get_need_pos_y()//dung de lay vi tri de ve process
	{
		return BK_objects[2].getPosition().y+BK_objects[2].getSize().y/2;
	}
	int get_request_pos_x()
	{
		return BK_objects[1].getPosition().x+BK_objects[1].getSize().x;
	}
	//qua trinh cong request se la: doi mau -> cong request vao allocation -> animation vao process -> xoa request -> dat vi tri request lai -> khi nao het request thi tien hanh cac buoc process
	//vẽ xong hết các thuộc tính rồi thì vẽ lại resource name do nó k có ngay, mặc dù vị trí thì giống y chang với thuộc tính nhưng vẫn k ngay, để lát xong vị trí thuộc tính rồi làm lại vị trí resource = cách đặt nó bằng vị trí thuộc tính 
	//tiếp tục vẽ hai có allocation và available, xong thì bắt đầu get các thuộc tính còn lại là max, need và request xong thì hiện thị -> vẽ hình 
	//shesh co may cai lam thanh ham dc ma quen ;-; de ranh thi lam lai
private:
	sf::RectangleShape BK_objects[MAX_OBJECTS];
	// vẽ 5 hình: 0 là quầy thu ngân hay available, 1 là quầy request, 2 là quầy need, 3 là khung hiển thị max của từng người,4 là khung hiển thị allocation của tất cả mn
	sf::Font font;
	sf::Text BK_objects_names[MAX_OBJECTS];
	sf::Text available_properties[MAX_PROPERTIES];
	sf::Text need_properties[MAX_PROPERTIES];
	sf::Text max_properties[MAX_PROPERTIES];
	sf::Text request_properties[MAX_PROPERTIES];
	sf::Text allocation_properties[MAX_THREAD][MAX_PROPERTIES];
	sf::Text process_names[MAX_THREAD];
	sf::Text resource_names[MAX_PROPERTIES];
	v<sf::Text> id_process;
	v<sf::Text> id_request;
	v<sf::CircleShape> process_circle;
	v<sf::CircleShape> request_circle;
	sf::RectangleShape status_table;//dung de hien thi trang thai cua man hinh, dang le la lam chung voi BK_objects nhung ma lam sau roi nen lam rieng luon de de kiem soat
	sf::Text status_name;
	sf::Text status;
};