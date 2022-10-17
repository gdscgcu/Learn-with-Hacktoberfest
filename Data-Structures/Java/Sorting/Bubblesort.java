public class Bubblesort {

    // Bubble sort = pairs of adjecent elements are compared , and the elements
    //              swaped if they are not in order.

    //              Quadratic time O(n^2)
    //              small data set = okey-ish
    //              large data set = bad
    public static  void main(String[] args) {
        int [] array= {9,6,7,3,4,2,8,5,1};

        bubblesort(array);

        for(int i: array)
        System.out.print(i);
    }
    public static void bubblesort(int [] array){

        for(int i=0; i<array.length-1; i++){       // this loop for compare every elements of array with others
            for(int j=0; j<array.length-i-1; j++){// this loop for give order to elements
                if(array[j]>array[j+1]){   // condition for checking 1st two elements with each other
                    int temp=array[j];  // if 1st element  is greater  then 2nd then it will store in temp
                    array[j]=array[j+1];   // then 1st element will be equal to 2nd
                    array[j+1]=temp;    // and 2nd is equal to temp which was 1st element
                }
            }
        }
    }
}
