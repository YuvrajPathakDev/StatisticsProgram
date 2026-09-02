//Finding the mean of the data :
#include <iostream> 
#include <vector> 
#include <cmath> 
#include <typeinfo>
#include <algorithm>

double dataMean(int numObs, double sumObs) {
    
    double MeanOfData;  
    MeanOfData = (sumObs) / numObs ;
    // std::cout <<"The mean of the given dataset is : "<< MeanOfData<<std::endl ; 
    return MeanOfData; 
}  

double dataMedian(const std::vector<double>&dataset, int numObs  ) {
    std::vector<double>vectorForSorting = dataset; 
    std::sort(vectorForSorting.begin(),vectorForSorting.end()); 
    
    // std::cout<<numOfObserve<<std::endl ; 
    // std::cout<<typeid(numOfObserve).name()<<std::endl ; //checking the type of numofObserve: it is double 

    // double sizeOfMedian = (numOfObserve+1)/2 ; 

    double remFromsizeOfMedian = (numObs)%2 ;
    // std::cout<<sizeOfMedian<<std::endl ;


    if(remFromsizeOfMedian == 0 ){
        return (vectorForSorting[numObs/2 -1]+vectorForSorting[numObs/2])/2; 
        
        
    }
    else{
        return vectorForSorting[numObs/2] ; // -1 because index starts from zero
    }
}

double standardDeviation (double sumOfObsSquared, int numObs, double meanofData) {
    double meanSquared= std::pow(meanofData,2) ; 
    return std::sqrt((sumOfObsSquared/numObs)-meanSquared); 

    

}

void dataMode(const std::vector<double>&dataset){
    std::vector<double>SortingDataset = dataset; 

    std::sort(SortingDataset.begin(), SortingDataset.end()); 
    std::vector<double>mode ; 
    int maxCount = 0 ; 


    for (size_t i = 0 ; i<SortingDataset.size() ;){
        
        double currentValue = SortingDataset[i];
        int currentCount = 0 ; 
        
        while (i< SortingDataset.size() && SortingDataset[i]==currentValue){

            i++ ; 
            currentCount ++ ; 
    
        }
        

        if (currentCount>maxCount){
            maxCount = currentCount; 
            mode.clear(); 
            mode.push_back(currentValue);

        }
        else if(currentCount==maxCount){
            mode.push_back(currentValue) ; 

        }

    }
    

    std::cout <<"Mode(s):"; 
    for (double m:mode){
        std::cout<<m<<"   ";
    }
    std::cout<<"\nFrequency Count: "<<maxCount<<"\n"; 



    
}

int main () {
    double sumObs = 0 ; //Sum of Observations 
    int numObs ; //Number of Observations (N)
    double sumOfObsSquared = 0 ; //Squared Sum of Observations 
    double meanOfObs; 
    double  medianOfObs ;   
    double sdofData ; 
    double maxValue, minValue ; 

    std::vector<double> dataset = {12,16,13,19,20,30,21,16,13,13}; 
    numObs = dataset.size() ; 


    maxValue =*std::max_element(dataset.begin() , dataset.end() ); 
    minValue =*std::min_element(dataset.begin() , dataset.end());
    

    std::cout<<"The given DATASET is"<<std::endl ; 

    for(double value: dataset){
        std::cout<<value; 
        std::cout<<"\t"; 
        sumObs += value  ; 
        
        sumOfObsSquared+= std::pow(value, 2); 

    }
    std::cout<<std::endl ;
    std::cout <<"The number of Observations: "<<numObs<<std::endl ;
    std::cout<<"The sum of Observations: "<<sumObs<<std::endl;
    std::cout<<"The sum of Obs Squared is "<<sumOfObsSquared<<std::endl <<std::endl ; 


    meanOfObs = dataMean(numObs,sumObs);
    std::cout<<"Mean: "<<meanOfObs<<std::endl; 
    
    medianOfObs = dataMedian (dataset,numObs);
    std::cout<<"Median: "<<medianOfObs<<std::endl; 

    std::cout<<"Maximum Value: "<<maxValue<<std::endl ; 
    std::cout<<"Minimum Value:"<<minValue<<std::endl ; 
    sdofData = standardDeviation (sumOfObsSquared,numObs,meanOfObs); 
    std::cout<<"Standard Deviation: "<<sdofData<<std::endl ; 
    std::cout<<"Variance: "<<std::pow(sdofData,2)<<std::endl; 
    std::cout<<"Coefficient of Variation: "<<(sdofData/meanOfObs)*100<<"%"<<std::endl ;
    std::cout<<"Range: " <<maxValue - minValue <<std::endl; 
    
    dataMode(dataset) ; 

    



    return 0 ; 


}