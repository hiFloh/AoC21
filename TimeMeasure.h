/**
 * @file TimeMeasure.h
 * @author Florian Gapp (florian@gapp-hsg.eu)
 * @brief class for measureing execution time.
 * @version 0.1
 * @date 2021-04-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <chrono>
#include <math.h>

namespace std{
    typedef std::ratio<1,1> normal;
    typedef std::ratio<60,1> minutes;
    typedef std::ratio<60*60,1> hours;
    typedef std::ratio<60*60*24,1> days;

    template<class T>
    double calcRatio()
    {
        return T().num/T().den;
    }
}


/**
 * @brief class for measureing execution time.
 * 
 */
class TimeMeasure
{
public:
	/**
	 * @brief Construct a new Time Measure object
	 * 
	 * @param average if true the average of all mesurements is kept else only the latest
	 */
	TimeMeasure(bool average = false) :_doAverage(average){}
	/**
	 * @brief stops the measurement
	 * and stores result
	 * and adds result
	 */
	void stop()
	{
		//stop timeing
		_to = std::chrono::high_resolution_clock::now();

		if (_doAverage && cycles>1)
		{//if not first element of average calculation
				_time += (_to - _from);
		}
		else
		{// if first element of average or no avergae
			_time = (_to - _from);
			cycles=0;
		}
		cycles++;
	}
	/**
	 * @brief starts a new measuremnt
	 * 
	 */
	void start()
	{
		_from = std::chrono::high_resolution_clock::now();
	}
    /**
     * @brief returns average time in through T defined ratio (std::ratio)
     * @tparam T std::ratio defining the unit
     * @return
     */
    template<class T>
    double getDuration()
    {
        return std::chrono::duration<double,T>((_to-_from)/cycles).count();
    }
    /**
     * @brief returns duration with less than 4 digits before comma
     * @return
     */
    double getDuration() {
        auto x = getIdealRatio();
        switch (x) {
            case ns:
                return getDuration<std::nano>();
            case us:
                return getDuration<std::micro>();
            case ms:
                return getDuration<std::milli>();
            case s:
                return getDuration<std::normal>();
            case m:
                return getDuration<std::minutes>();
            case h:
                return getDuration<std::hours>();
            case d:
                return getDuration<std::days>();
        }
        return 0;
    }

    /**
     *
     * @param lon
     * @returns short unit string used for getDuration() if lon=false
     * @returns long unit string used for getDuration() if lon=true
     */
    std::string getDurationUnit(bool lon=false){
        auto x= getIdealRatio();
        if(lon) {
            switch (x) {
                case ns:
                    return "nanoseconds";
                case us:
                    return "microseconds";
                case ms:
                    return "milliseconds";
                case s:
                    return "seconds";
                case m:
                    return "minutes";
                case h:
                    return "hours";
                case d:
                    return "days";
            }
        }
        else
        {
            switch (x) {
                case ns:
                    return "ns";
                case us:
                    return "us";
                case ms:
                    return "ms";
                case s:
                    return "s";
                case m:
                    return "m";
                case h:
                    return "h";
                case d:
                    return "d";
            }
        }
        return "";
    }
	/**
	 * @brief Creates a new TimeMeasure Object and starts measurement
	 * 
	 * @return DurationMeasure 
	 */
	static TimeMeasure from() {
		TimeMeasure s;
		s.start();
		return s;
	}
    enum units{
        d,h,m,s,ms,us,ns
    };
private:
	std::chrono::high_resolution_clock::time_point _from;	//	start time
	std::chrono::high_resolution_clock::time_point _to;		// stop time
	bool _doAverage;
	size_t cycles=0;
	std::chrono::nanoseconds _time;
    /**
     *
     * @return unit best fit for readability
     */
    units getIdealRatio(){
        auto x= getDuration<std::normal>();
        if(x< std::calcRatio<std::micro>())
        {
            return ns;
        }
        else if (x<std::calcRatio<std::milli>())
        {
            return us;
        }
        else if(x<std::calcRatio<std::normal>())
        {
            return ms;
        }
        else if(x<std::calcRatio<std::minutes>())
        {
            return s;
        }
        else if(x<std::calcRatio<std::hours>())
        {
            return m;
        }
        else if(x<std::calcRatio<std::days>())
        {
            return h;
        }
        else
        {
            return d;
        }
    }
};
