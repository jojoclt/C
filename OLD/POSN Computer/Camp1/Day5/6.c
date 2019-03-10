float average(int a[10]){
    int i,j=0;
    float k;
    for (i=0;i<10;i++){
        j+=a[i];
    }
    k=(float)j/10;
    return k;
}
main(){
    int a[10],i;
    for (i=0;i<10;i++)
        scanf("%d",&a[i]);
    printf("The average score is %f",average(a));
}
