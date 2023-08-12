```C++
Collection<double> Cdbl;
Cdbl.add(1.23);
Cdbl.add(2.34);
Cdbl.add(3.45);
cout << "There are " << Cdbl.size() << " items in the Collection!" << endl;
for(int i=0; i< Cdbl.size();i++){
    cout << Cdbl[i] << endl;
}
```
Output:
```Text
There are 3 items in the Collection!
1.23
2.34
3.45
```
