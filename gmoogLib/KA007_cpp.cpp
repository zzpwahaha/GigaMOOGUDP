// KA007_cpp.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"
#include <iostream>

#include <thread>
#include <chrono>

#include "BoostUDP.h"
#include <windows.h>

#include "MessagePrinter.h"
#include "MessageSender.h"

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

//int test() {
//	//_crtBreakAlloc = 172;
//	{
//		MessageSender ms;
//
//		//invalid messages
//
//		/*Message m = Message::make().destination(MessageDestination::KA007).DAC(MessageDAC::DAC1).channel(0).setting(MessageSetting::LOADFREQUENCY);
//		ms.enqueue(m);
//
//		Message m2 = Message::make().destination(MessageDestination::KA007).DAC(MessageDAC::DAC1).setting(MessageSetting::LOADFREQUENCY);
//		ms.enqueue(m2);
//
//		Message m3 = Message::make().destination(MessageDestination::KA007)
//			.DAC(MessageDAC::DAC1).channel(100)
//			.setting(MessageSetting::LOADFREQUENCY).frequencyMHz(168);
//		ms.enqueue(m3);*/
//
//		//valid messages
//		Message m4 = Message::make().destination(MessageDestination::KA007)
//			.DAC(MessageDAC::DAC1).channel(1)
//			.setting(MessageSetting::LOADFREQUENCY).frequencyMHz(168.245762);
//		ms.enqueue(m4);
//
//		Message m5 = Message::make().destination(MessageDestination::KA007)
//			.DAC(MessageDAC::DAC1).channel(63)
//			.setting(MessageSetting::LOADFREQUENCY).frequencyMHz(168);
//		ms.enqueue(m5);
//
//		Message m6 = Message::make().destination(MessageDestination::KA007)
//			.setting(MessageSetting::TERMINATE_SEQ);
//		ms.enqueue(m6);
//
//		ms.getQueueElementCount();
//
//		//ms.sendAll();
//
//		//for Arduino:
//		//BoostAsyncSerial ser("COM27", 115200);
//		//std::vector<int> data = { 50 };
//
//		//BoostAsyncSerial ser("COM34", 115200);
//		BoostAsyncSerial ser(
//			"COM6",
//			115200,
//			8,
//			boost::asio::serial_port_base::stop_bits::one,
//			boost::asio::serial_port_base::parity::none,
//			boost::asio::serial_port_base::flow_control::none
//		);
//
//		MessagePrinter rec;
//
//		ser.setReadCallback(boost::bind(&MessagePrinter::callback, rec, _1));
//
//		bool exit = false;
//
//		std::cout << "press esc to exit! " << std::endl;
//
//		using namespace std::chrono_literals;
//
//		std::vector<int> data = { 0x10, 1, 1, 2, 3, 4, 5, 6, 0x20, 0, 3, 4 };
//
//		while (exit == false)
//		{
//			if (GetAsyncKeyState(VK_ESCAPE))
//			{
//				exit = true;
//			}
//			ser.write(data);
//			std::this_thread::sleep_for(std::chrono::milliseconds(50));
//		}
//
//		std::cout << "exiting..." << std::endl;
//	}
//	//_CrtDumpMemoryLeaks();
//
//	return 0;
//}

int run() {
	//_crtBreakAlloc = 172;
	{
		MessageSender ms;

		//for (int channel = 0; channel < 64; channel++) {
		//	Message m = Message::make().destination(MessageDestination::KA007)
		//		.DAC(MessageDAC::DAC0).channel(channel)
		//		.setting(MessageSetting::LOADFREQUENCY)
		//		.frequencyMHz(145.0 + 90.0/64*channel).amplitudePercent(100).phaseDegrees(0.0);
		//	ms.enqueue(m);
		//}
		
		{
			Message m = Message::make().destination(MessageDestination::KA007)
				.DAC(MessageDAC::DAC0).channel(0)
				.setting(MessageSetting::LOADFREQUENCY)
				.frequencyMHz(100).amplitudePercent(100).phaseDegrees(0.0);
			ms.enqueue(m);

			Message m2 = Message::make().destination(MessageDestination::KA007)
				.DAC(MessageDAC::DAC0).channel(1)
				.setting(MessageSetting::LOADFREQUENCY)
				.frequencyMHz(101).amplitudePercent(100).phaseDegrees(0.0);
			ms.enqueue(m2);
		}

		for (int channel = 2; channel < 64; channel++) {
			Message m = Message::make().destination(MessageDestination::KA007)
				.DAC(MessageDAC::DAC0).channel(channel)
				.setting(MessageSetting::LOADFREQUENCY)
				.frequencyMHz(0).amplitudePercent(0).phaseDegrees(0.0);;
			ms.enqueue(m);
		}

		for (int channel = 0; channel < 64; channel++) {
			Message m = Message::make().destination(MessageDestination::KA007)
				.DAC(MessageDAC::DAC1).channel(channel)
				.setting(MessageSetting::LOADFREQUENCY)
				.frequencyMHz(0).amplitudePercent(0).phaseDegrees(0.0);;
			ms.enqueue(m);
		}

		for (int channel = 0; channel < 64; channel++) {
			Message m = Message::make().destination(MessageDestination::KA007)
				.DAC(MessageDAC::DAC2).channel(channel)
				.setting(MessageSetting::LOADFREQUENCY)
				.frequencyMHz(0).amplitudePercent(0).phaseDegrees(0.0);;
			ms.enqueue(m);
		}

		for (int channel = 0; channel < 64; channel++) {
			Message m = Message::make().destination(MessageDestination::KA007)
				.DAC(MessageDAC::DAC3).channel(channel)
				.setting(MessageSetting::LOADFREQUENCY)
				.frequencyMHz(0).amplitudePercent(0).phaseDegrees(0.0);;
			ms.enqueue(m);
		}

		{
			Message m = Message::make().destination(MessageDestination::KA007)
				.setting(MessageSetting::TERMINATE_SEQ);
			ms.enqueue(m);
		}

		ms.getQueueElementCount();

		BoostUDP fpga("192.168.7.179", 804);

		MessagePrinter rec;

		fpga.setReadCallback(boost::bind(&MessagePrinter::callback, rec, _1));

		//std::vector<int> data = { 0x00, 1, 1, 2, 3, 4, 5, 6, 0x00, 0, 3, 4 };
		//std::vector<int> data = { 0, 0, 0, 0 ,0, 0, 0, 0 ,0, 0, 0, 0 ,0, 0, 0, 0 };
		//fpga.write(data);

		fpga.write(ms.getMessageBytes());
		//TODO: removed arduino trigger
		//for Arduino:
		//BoostAsyncSerial arduino("COM27", 115200);
		//std::vector<int> Trigger_Pin2 = { 50 };
		//std::vector<int> Trigger_Pin3 = { 51 };

		/*using namespace std::chrono_literals;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		arduino.write(Trigger_Pin2);*/

		bool exit = false;

		//std::cout << "press esc to exit! " << std::endl;

		//using namespace std::chrono_literals;

		//while (exit == false)
		//{
		//	if (GetAsyncKeyState(VK_ESCAPE))
		//	{
		//		exit = true;
		//	}
		//	//arduino.write(Trigger_Pin3);
		//	std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//}

		std::cout << "exiting..." << std::endl;
	}
	//_CrtDumpMemoryLeaks();

	return 0;
}

int main()
{
	//test();
	run();
}