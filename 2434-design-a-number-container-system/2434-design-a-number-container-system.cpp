class NumberContainers {
public:
    unordered_map<int, int> indexToNumber;  // Stores {index -> number}
    unordered_map<int, set<int>> numberToIndices;  // Stores {number -> set of indices}
    NumberContainers() {
   
    }
    
    void change(int index, int number) {
       if(indexToNumber.find(index)!=indexToNumber.end())
       {
          int storedNumber = indexToNumber[index];
           numberToIndices[storedNumber].erase(index);
            if (numberToIndices[storedNumber].empty()) {
                numberToIndices.erase(storedNumber);  // Remove entry if set is empty
            }
       }
       indexToNumber[index] = number;
        numberToIndices[number].insert(index);  // Add index to the new number's set
      
    }
    
    int find(int number) {
       if (numberToIndices.find(number) == numberToIndices.end() || numberToIndices[number].empty()) {
                return -1; 
        }
        return *numberToIndices[number].begin();  
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */