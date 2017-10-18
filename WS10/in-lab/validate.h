#ifndef ict_validate_h
#define ict_validate_h
namespace ict {
	template<typename T>
	bool validate(const T& min, const T& max, const T testValue[], const int noElem, bool bools[]) {
		bool rtn;
		int count = 0;
		for (int i = 0; i < noElem; i++) {
			if (testValue[i] <= max && testValue[i] >= min) {
				bools[i] = true;
				count++;
			}
			else {
				bools[i] = false;
			}
		}
		if (count == noElem)
			rtn = true;
		else
			rtn = false;
		return rtn;
	}
}
#endif // !sict_validate_h

