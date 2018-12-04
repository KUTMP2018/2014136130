#ifndef CShiftPWM_h
#define CShiftPWM_h

#include <Arduino.h>

class CShiftPWM{
public:
	CShiftPWM(int timerInUse, bool noSPI, int latchPin, int dataPin, int clockPin);
	~CShiftPWM();

public:
	void Start(int ledFrequency, unsigned char max_Brightness);
	void SetAmountOfRegisters(unsigned char newAmount);
	void SetPinGrouping(int grouping);
	void PrintInterruptLoad(void);
	void OneByOneSlow(void);
	void OneByOneFast(void);
	void SetOne(int pin, unsigned char value);
	void SetAll(unsigned char value);

	void SetGroupOf2(int group, unsigned char v0, unsigned char v1, int offset = 0);
	void SetGroupOf3(int group, unsigned char v0, unsigned char v1, unsigned char v2, int offset = 0);
	void SetGroupOf4(int group, unsigned char v0, unsigned char v1, unsigned char v2, unsigned char v3, int offset = 0);
	void SetGroupOf5(int group, unsigned char v0, unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, int offset = 0);

	void SetRGB(int led, unsigned char r,unsigned char g,unsigned char b, int offset = 0);
	void SetAllRGB(unsigned char r,unsigned char g,unsigned char b);
	void SetHSV(int led, unsigned int hue, unsigned int sat, unsigned int val, int offset = 0);
	void SetAllHSV(unsigned int hue, unsigned int sat, unsigned int val);

private:
	void OneByOne_core(int delaytime);
	bool IsValidPin(int pin);
	void InitTimer1(void);
	
	#if defined(OCR3A)
		// Arduino Leonardo or Micro (32u4)
		void InitTimer3(void);
	#endif

	#if defined(OCR2A)
		// Normal Arduino (328)
		void InitTimer2(void);
	#endif

	bool LoadNotTooHigh(void);

	const int m_timer;
	const bool m_noSPI;
	const int m_latchPin;
	const int m_dataPin;
	const int m_clockPin;

	int m_prescaler;


public:
	int m_ledFrequency;
	unsigned char m_maxBrightness;
	unsigned char m_amountOfRegisters;
	int m_amountOfOutputs;
	int m_pinGrouping;
	unsigned char * m_PWMValues;
	unsigned char m_counter;

};

#endif
