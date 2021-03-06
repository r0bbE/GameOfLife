#include "TimerClass.h"

TimerClass::TimerClass()
{
}

TimerClass::TimerClass(const TimerClass& other)
{
}

TimerClass::~TimerClass()
{
}

void TimerClass::StartTimer()
{
	startTime = high_resolution_clock::now();
}

double TimerClass::GetTime() const
{
	std::chrono::duration<double> roundTime = duration_cast<duration<double>>(high_resolution_clock::now() - startTime);
	return roundTime.count();
}

std::string TimerClass::GetFormattedDuration(std::string text) const
{
	auto end = high_resolution_clock::now();
	auto diff = end - startTime;

	auto hours = duration_cast<std::chrono::hours>(diff);
	diff -= hours;

	auto mins = duration_cast<minutes>(diff);
	diff -= mins;

	auto secs = duration_cast<seconds>(diff);
	diff -= secs;

	auto millis = duration_cast<milliseconds>(diff);

	std::stringstream outstream("");

	outstream << text.c_str();
	outstream << std::setfill('0');
	outstream << std::setw(2) << hours.count() << ':'
		<< std::setw(2) << mins.count() << ':'
		<< std::setw(2) << secs.count() << '.'
		<< std::setw(3) << millis.count() << ";";

	return outstream.str();
}

std::string TimerClass::FormatTime(double time) const
{
	duration<double> diff = duration<double>(time);

	auto hours = duration_cast<std::chrono::hours>(diff);
	diff -= hours;

	auto mins = duration_cast<minutes>(diff);
	diff -= mins;

	auto secs = duration_cast<seconds>(diff);
	diff -= secs;

	auto millis = duration_cast<milliseconds>(diff);

	std::stringstream outstream("");

	outstream << std::setfill('0');
	outstream << std::setw(2) << hours.count() << ':'
		<< std::setw(2) << mins.count() << ':'
		<< std::setw(2) << secs.count() << '.'
		<< std::setw(3) << millis.count() << ";";

	return outstream.str();
}
