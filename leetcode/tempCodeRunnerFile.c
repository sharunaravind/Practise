bool increasingTriplet(int* arr, int n) {
    int curr=arr[0],prev=arr[0],topYet=arr[0],count=1;
    for(int i=1;i<n;i++)
    {
        curr=arr[i];
        if(curr>prev || curr>topYet)
        {
            count++;
        }
        else{
            if(count==2 && topYet>prev){
                topYet=prev;
            }
        }
        if(count>=3)
        {
            return true;
        }
        prev=curr;
    }
    return false;
}