/*Natalie Brooks, 116009829, nkbrooks
 */
#include <stdio.h>
#include <math.h>
#define MAX 50

float compute_data(int arr[], int penalty,
		   int Number_of_Assignments,
		   float numeric_value,
		   int combined_weight);
float compute_data_copy(int arr[], int penalty,
			int Number_of_Assignments,
			float numeric_value,
			int combined_weight);
/*computes numeric score after dropped assignments */
float compute_data_copy(int arr[], int penalty, int
			Number_of_Assignments,
			float numeric_value,
			int combined_weight){
  int i;
  float temp, weight_float;
  static float ans = 0;
  
  for(i = 0; i < (Number_of_Assignments * 4); i+=4){
	 if(arr[i+1] != 150){
	   temp = ((arr[i+1]/100.0)*arr[i+2]);
	  ans += (temp);
	 }	 
  }

    numeric_value = ans;

    weight_float = combined_weight;

    return (numeric_value/weight_float) *100.0;

}

/*finds minimum and drops the lowest score */
float drop_classes(int Number_Of_Assignments_to_Drop, int arr[],
		   int Number_of_Assignments,int assignment_number,
		   int combined_weight,
		    float  numeric_score,
		   int Points_Penalty_Per_Day_Late ){
  int k,i;
  int index = 1, min; 
  int length =  Number_of_Assignments*4;
  int counter = 0;
 
   for(k = 0; k < Number_Of_Assignments_to_Drop; k++){
   
     min = arr[index];
   
    for(index = 1; index < length; index+=4){

      if(arr[index+4] != 0){
      if(min > arr[index+4]){
	min = arr[index+4];
      }
      else if (min < arr[index+4]){
	min = min;
      }
      } else {
	break;
      }
  
      counter++;
      
    }
	
     for (i=1; i < length; i+=4) {
      if (arr[i] == min){
	
	arr[i] = 150;

	combined_weight = combined_weight - arr[i+1];

      }
      
     }
      min = arr[1];
   }

  numeric_score = compute_data_copy(arr, Points_Penalty_Per_Day_Late,
				    Number_of_Assignments,
				    numeric_score, combined_weight);

  return numeric_score;
}

/*adds input information into the array */

int *add_data(int *arr, int Number_of_Assignments,
	      int assignment_number, int assignment_score,
	 float assignment_weight, int days_late){

  int index = (assignment_number - 1)*4;
  arr[index] = assignment_number;
  arr[index+1] = assignment_score;
  arr[index+2] = assignment_weight;
  arr[index+3] = days_late;

  return arr;
}
/*makes new array from orginial array to alter*/
int *add_copy_data(int *copy, int Number_of_Assignments,
		   int penalty, int assignment_number){
  int i;
  int temp = 0;
  int days_late;
  
  for(i = 0; i < (Number_of_Assignments * 4); i+=4){
      days_late = copy[i+3];
      
       if(days_late != 0){
	 temp = (copy[i+1] - (days_late * penalty));
	 copy[i+1] = temp;
		  	 
     }
 }
       
	   return copy;
}
		
   
/*standard deviation*/
float get_SD(int arr[], int penalty, int Number_of_Assignments,float mean){
  int i;
  int days_late;
  float temp;
  static float ans = 0;
  float SD;
  for(i = 0; i < (Number_of_Assignments * 4); i+=4){
      days_late = arr[i+3];
       if(days_late != 0){

	 temp =  (arr[i+1] - (days_late * penalty));
	 

      }else{
	 temp =  (arr[i+1]);

      }
    
       ans += pow(temp - mean,2);
    }
  
  SD = sqrt(ans/Number_of_Assignments);

  return SD;

}

/*mean*/
float get_mean(int arr[], int penalty, int Number_of_Assignments){
  int i;
  int assignment_score;
  static float real_total = 0;
  int real_score = 0;
  int days_late;
  for(i = 0; i < (Number_of_Assignments * 4); i+=4){
    assignment_score = arr[i+1];
      days_late = arr[i+3];
       if(days_late != 0){

	 real_score = (assignment_score - (days_late * penalty));

	 real_total += real_score;

    }else{

	 real_score = (assignment_score);

	 real_total += real_score;
      }

    }
      return real_total/(Number_of_Assignments);

   }
/*find numeric score*/
float compute_data(int arr[], int penalty,
		   int Number_of_Assignments, float numeric_value,
		   int combined_weight){
  int i;
  int days_late, weight;
  float temp;
  static float ans = 0;
  
  for(i = 0; i < (Number_of_Assignments * 4); i+=4){
      days_late = arr[i+3];
      weight = arr[i+2];
       if(days_late != 0){
	 temp = ((arr[i+1] - (days_late * penalty))/100.0)*weight;
	  

      }else{
	
	   temp = ((arr[i+1]/100.0)*weight);
	
       }
    
       ans += (temp);
  }
   
    return (ans/combined_weight) *100.0;

}


int main(){

  int Points_Penalty_Per_Day_Late;
  int Number_Of_Assignments_to_Drop;
  char Stats; 
  int Number_of_Assignments;
  int i,j;
  int assignment_number = 0, assignment_score = 0;
  float assignment_weight = 0;
  int days_late = 0;
  float Standard_Deviation;
  static float total= 0, weight_total = 0;
  float mean, numeric_score;
  int arr[MAX];
  int copy[MAX];
  int *data;
  int loop;
   
  data = arr;
  
  scanf(" %d %d %c",&Points_Penalty_Per_Day_Late,
	&Number_Of_Assignments_to_Drop,&Stats);
  
  scanf(" %d",&Number_of_Assignments);
 
    for(i = 1; i <= Number_of_Assignments; i++){
  
    scanf(" %d, %d, %f, %d", &assignment_number, &assignment_score,
	  &assignment_weight,&days_late);
    
    /*adds data to array*/
    add_data(arr, Number_of_Assignments, assignment_number,
	     assignment_score, assignment_weight, days_late);

    total += assignment_score;
    weight_total += assignment_weight;
    
   }

    /*makes copy array*/
    for(loop = 0; loop < Number_of_Assignments*4; loop++) {
      copy[loop] = arr[loop];
   }

    add_copy_data(copy, Number_of_Assignments,
		  Points_Penalty_Per_Day_Late, assignment_number);

    
   if(weight_total == 100){
   if(Number_Of_Assignments_to_Drop != 0) {
     numeric_score = drop_classes(Number_Of_Assignments_to_Drop,
				  copy, Number_of_Assignments,
		assignment_number, weight_total, numeric_score,
				  Points_Penalty_Per_Day_Late );
   } else {
   numeric_score = compute_data(arr, Points_Penalty_Per_Day_Late,
				Number_of_Assignments,
				numeric_score, weight_total);
   }
   printf("Numeric Score: %5.4f\n", numeric_score);
   
   printf("Points Penalty Per Day Late: %d\n",
	  Points_Penalty_Per_Day_Late);
   printf("Number of Assignments Dropped: %d\n",
	  Number_Of_Assignments_to_Drop);
   printf("Values Provided:\n");
   printf("Assignment, Score, Weight, Days Late\n");

   /*print numbers*/
   
   for(j = 0; j <= assignment_number*4; j+= 4){
     printf("%d, %d, %d, %d\n", data[j],data[j+1],data[j+2],data[j+3]);
       
     }
   /*if yes, print stats*/
   if(Stats == 'Y'){
   mean = get_mean(arr, Points_Penalty_Per_Day_Late,
		   Number_of_Assignments);
   printf("Mean: %5.4f, ",mean);
   
   Standard_Deviation = get_SD(arr, Points_Penalty_Per_Day_Late,
			       Number_of_Assignments, mean);
   
   printf("Standard Deviation: %5.4f\n", Standard_Deviation);

   return 1;
   
   }else {
     return 0;
    }
    
   } else {
     printf("ERROR: Invalid values provided");
     return 0;
  
   }
  return 1;

}







