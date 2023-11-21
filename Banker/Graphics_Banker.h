//#pragma once
//#include <SFML/Graphics.hpp>
//#include "banker_objects.h"
//#include"Banker.h"
//#include <iostream>
//class graphics_banker
//{
//public:
//    graphics_banker() {};
//    ~graphics_banker() {};
//    void graphics(Banker A, sf::Font font, sf::Color color)
//    {
//        sf::RenderWindow window(sf::VideoMode(1280, 800), "BANKER");
//        int nums_processes = A.GetN();;
//        int nums_properties = A.GetM();
//        banker_objects banker_objects(nums_processes, nums_properties);
//        banker_objects.init_banker_objects(1280, 800, 15, font, sf::Color::Red,);//1280 va 800 la kich co man hinh, 15 la co chu
//        while (window.isOpen())
//        {
//            sf::Event event;
//            while (window.pollEvent(event))
//            {
//                if (event.type == sf::Event::Closed)
//                    window.close();
//            }
//
//            window.clear();
//
//            // Vẽ hình chữ nhật với đường viền
//            banker_objects.draw_objects(window);
//            banker_objects.draw_process_name(window);
//            banker_objects.draw_resource(window);
//            banker_objects.draw_Available(window);
//            banker_objects.draw_Allocation(window);
//            window.display();
//        }
//
//    }
//};
//// vẽ 5 hình: 1 là quầy thu ngân hay available, 2 là quầy need, 3 là quầy request, 4 là khung hiển thị  allocation của từng người,5 là khung hiển thị allocation của tất cả mn
////tiếp theo là vẽ người xếp hàng, chắc bằng animation quá 
