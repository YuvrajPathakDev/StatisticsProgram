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

double dataMedian(const std::vector<double>&vectorForSorting, int numObs  ) {
    std::vector<double>SortedVector = vectorForSorting;  
    
    // std::cout<<numOfObserve<<std::endl ; 
    // std::cout<<typeid(numOfObserve).name()<<std::endl ; //checking the type of numofObserve: it is double 

    // double sizeOfMedian = (numOfObserve+1)/2 ; 

    int remFromsizeOfMedian = (numObs)%2 ;
    // std::cout<<sizeOfMedian<<std::endl ;


    if(remFromsizeOfMedian == 0 ){
        // -1 because index starts from zero
        return (SortedVector[(numObs/2)-1]+SortedVector[numObs/2])/2; 
        
        
    }
    else{
        return SortedVector[(numObs/2)] ;
    }
}

double standardDeviation (double sumOfObsSquared, int numObs, double meanofData) {
    double meanSquared= std::pow(meanofData,2) ; 
    return std::sqrt((sumOfObsSquared/numObs)-meanSquared); 

    

}

void dataMode(const std::vector<double>&vectorForSorting){
    std::vector<double>SortingDataset = vectorForSorting; 
    // std::vector <int> countVector; 
    int maxFrequency = 0 ; 
    double modeValue = 0 ; 
    int modeCount = 0 ; 

    for (int i =0 ; i<SortingDataset.size();){
        int count = 1  ;

       
        while(i+1< SortingDataset.size() && SortingDataset[i]==SortingDataset[i+1]){
            count++; 
            i++; 
            
    }
    // countVector.push_back(count); 

    if(count>maxFrequency){
        maxFrequency= count ; 
        modeValue = SortingDataset[i]; 
        modeCount=1 ;  

    }
    else if (count == maxFrequency){
        modeCount++ ;
    }
    
    i++; 

    }


    // std::cout<<"The Frequency distribution of the sorted dataset is:\n"; 
    // for (int k:countVector){
    //     std::cout<<k<<"\t"; 
    // }


    if(modeCount>1){
        std::cout<<"The distribution has multiple modes." <<std::endl ; 
         
    }
    else{ 
        
        std::cout<<"The max frequency is :"<<maxFrequency<<std::endl ;
        
        std::cout<<"The mode Value is: "<<modeValue<<std::endl ; 

    }



   
}
    

    

double FirstQuartile (const std::vector<double>&vectorForSorting){
    std::vector<double>SortedVector = vectorForSorting ; 
    int noOfElements = SortedVector.size() ;
    int remainder = (noOfElements+1)%4 ; 
    if (remainder!=0){
        return SortedVector[(noOfElements)/4 - 1] + (static_cast<double>(remainder/4.0)* (SortedVector[(noOfElements)/4]-SortedVector[(noOfElements)/4 - 1 ])); 
    }
    else{
        return SortedVector[(noOfElements)/4 ]; 

    }
}

double ThirdQuartile(const std::vector<double>&vectorForSorting){
    std::vector<double>SortedVector = vectorForSorting ; 
    int noOfElements = SortedVector.size() ;
    int remainder =(3*(noOfElements+1))%4 ; 
    std::cout<<remainder<<std::endl ; 
    if (remainder!=0){
        return SortedVector[3*(noOfElements)/4 - 1] + (static_cast<double>(remainder/4.0)* (SortedVector[(noOfElements)/4]-SortedVector[(noOfElements)/4 - 1 ])); 
    }
    else{
        return SortedVector[3*(noOfElements)/4 ]; 
    }


}

double KarlCoeff(double ObsMean, double ObsMedian, double ObsSD) {
    double relKarlCoeff = 3*(ObsMean-ObsMedian)/ObsSD; 
    return relKarlCoeff ;


}

void checkSkewness(double KarlCoef) { 
    if(KarlCoef==0){
        std::cout <<"Symmetrical dataset"; 
    }
    else if(KarlCoef>0){
        std::cout<<"Positively Skewed dataset"; 
    }

    else{
        std::cout<<"Negatively Skewed dataset"; 
    }
}


int main () {
    double sumObs = 0 ; //Sum of Observations 
    int numObs ; //Number of Observations (N)
    double sumOfObsSquared = 0 ; //Squared Sum of Observations 
    double meanOfObs; 
    double  medianOfObs ;   
    double sdofData ; 
    double maxValue, minValue ; 

    std::vector<double> dataset = {12,16,14,17,19,34,31,32,32,32,32,32,32,5,11,12,34,88,12,76,12,12,12}; 
    numObs = dataset.size() ; 
    std::vector<double>vectorForSorting = dataset; 
    std::sort(vectorForSorting.begin(),vectorForSorting.end()); 


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
    std::cout<<"The sorted Dataset is:"<<std::endl ; 
    for(double value: vectorForSorting){
        std::cout<<value; 
        std::cout<<"\t"; 

    }
    std::cout<<"\n"; 

    std::cout <<"The number of Observations: "<<numObs<<std::endl ;
    std::cout<<"The sum of Observations: "<<sumObs<<std::endl;
    std::cout<<"The sum of Obs Squared is "<<sumOfObsSquared<<std::endl <<std::endl ; 


    meanOfObs = dataMean(numObs,sumObs);
    std::cout<<"Mean: "<<meanOfObs<<std::endl; 
    
    medianOfObs = dataMedian (vectorForSorting,numObs);
    std::cout<<"Median: "<<medianOfObs<<std::endl; 

    std::cout<<"Maximum Value: "<<maxValue<<std::endl ; 
    std::cout<<"Minimum Value:"<<minValue<<std::endl ; 
    sdofData = standardDeviation (sumOfObsSquared,numObs,meanOfObs); 
    std::cout<<"Standard Deviation: "<<sdofData<<std::endl ; 
    std::cout<<"Variance: "<<std::pow(sdofData,2)<<std::endl; 
    std::cout<<"Coefficient of Variation: "<<(sdofData/meanOfObs)*100<<"%"<<std::endl ;
    std::cout<<"Range: " <<maxValue - minValue <<std::endl; 
    
    
    dataMode(vectorForSorting) ; 

    std::cout<<"The First Quartile is :"<<FirstQuartile(vectorForSorting)<<std::endl; 
    std::cout <<"The Third Quartile is :"<<ThirdQuartile(vectorForSorting)<<std::endl ; 


    double relativeKarlCoeff = KarlCoeff(meanOfObs,medianOfObs,sdofData); 
    std::cout <<"The Karl Coefficient of the dataset is:"<<relativeKarlCoeff<<std::endl; 

    checkSkewness(relativeKarlCoeff) ; 




    return 0 ; 


}//The Frequency Count of Mode, Median,Q1, Q3 of the datasets have Wrong Logic ; 