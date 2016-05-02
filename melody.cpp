#include <iostream>
using std::cout; using std::endl;
#include <math.h>
#include <typeinfo>
#include <string>
using std::stol; using std::stod;
#include <cstdlib>
using std::atof;
#include <sstream>
using std::stringstream;
#include <algorithm>
using std::transform;

#include "class.h"


//split function
void split(string line, vector<string>&words, string good_chars){
	line = line + " ";
	string word;
	for(auto k : line){
		if(good_chars.find(k)!=string::npos){
			word.push_back(k);


		}
		else{
			if(word.size()){
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				words.push_back(word);

			}
			word = "";
		}
	}
}




Melody::Melody(string notes_file_name, string wav_file_name, long a_beat) 
: ofs_(wav_file_name, std::ios::binary), ifs_(notes_file_name), one_beat_(a_beat){}


void Melody::fill_Note_vector(){
	
	string good_chars = "012345678910.";
	vector<string> nums;

	
	long value1, value2;
	
	ifs_ >> value1;
	ifs_ >> value2;
	
	samples_per_sec_ = value1;
	volume_ = value2;
	
	string line;
	
	while(ifs_ >> line){
		
		split(line, nums, good_chars);
		
	}
	
	for(unsigned int i = 0; i < nums.size(); i ++){
		
		//oct = nums[i][0], pch = nums[i][2], dur = nums[i][4]

		
		double freq;
		
		stringstream s1;
		double oct;
		
		stringstream s2;
		double pch;
		
		stringstream s3;
		double dur;
		
		s1 << nums[i][0];
		s1 >> oct;
		
		s2 << nums[i][2];
		s2 >> pch;
		
		s3 << nums[i][4];
		s3 >> dur;
				
		
		freq = 440*pow(2, (oct-4 + ((pch-9)/12.0)));
			
		Note mynote(freq,dur);
		
		v_.push_back(mynote);
		
		
	}

	
}

void Melody::generate_wave_data(){
	
	
	
	double one_increment, sample, volume;
	
	const double TwoPI = 2.0 * (atan(1.0) * 4.0);
	
	for(auto n : v_){
		
		double freq, dur;
		
		freq = n.freq_;
		dur = n.dur_;
		volume = volume_;
		
		
		for (double val=0; val < one_beat_ * dur; val++){
			
			one_increment = freq * (val / (samples_per_sec_));
			sample = sin( one_increment * TwoPI );
			sample = sample * volume;
			
			w_.push_back(sample);
			
		
		}
		
		
	}
	

	
}
