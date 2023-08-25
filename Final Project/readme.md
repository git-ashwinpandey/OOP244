When Books and other publications arrive in the Seneca library, they should be tagged and put on shelves, so they are easily retrievable to be lent out to those who need them. 
Your task is to design an application that receives the publications and stores them into the system with the information needed for their retrieval. 

# Milestone 1
### Date Class	
A class the encapsulates year, and month and day values for Date stamp, comparison and Date IO purposes. 
### MenuItem Class	
A class that hold a text Item; (an option or title to be displayed) in a menu to be selected by the user. This is a fully private class that is only accessible by Menu (see next class)
### Menu Class	
A class that has several MenuItems to be displayed so the user can select one of them for an action to be executed in the program 

### Date output sample

> Note that the current date will change based on the day of execution

```Text
Current Date: 2023/06/26
0 days since ms1 was published
Please enter a date to be compared to 2023/06/26
(Also try some invalid values for testing):
YYYY/MM/DD > abc
cin Failed, Please try again > 2023/0/0
Bad Month Value, Please try again > 2023/10/30
Your Entry: 2023/10/30
Set by program to 2023/06/26: 2023/06/26
Days between the two dates: 126
All the following statements must be correct:
2023/10/30 > 2023/06/26
2023/10/30 >= 2023/06/26
2023/10/30 > 2023/06/26
2023/10/30 >= 2023/06/26
2023/10/30 != 2023/06/26
2023/10/30 != 2023/06/26
```

## Menu tester program
[menuTester.cpp](MS1/menuTester.cpp)

### Sample Execution

```Text
The >< menu is empty
The Lunch Menu is not empty and has 3 menu items.
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> abc
Invalid Selection, try again: 5
Invalid Selection, try again: -1
Invalid Selection, try again: 0
 1- Order more
 0- Exit
> 0
Your orders:
2 Omelets
3 Tuna Sandwichs

```

# Milestone 2
## The Seneca Library Application Module
## The run method

The run method is the main application driver.

It displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.

When the user selects exit, the value of `m_changed` is examined. 
If the value is false, then since the data of the application is not modified, the program terminates.

If the value is true, the `m_exitMenu` is used by calling its run method. Doing so the user has the selection of saving and exiting, cancelling and going back to the main menu or exiting without saving. 

If the first one is selected, the `save()` method is called and the program terminates.

If the second one is selected the program goes back to the main menu and execution continues.

If the exit is selected, then the confirm menu will be called using the message: `"This will discard all the changes are you sure?"`.  If the user selects **Yes**, the program terminates. Otherwise, the program goes back to the main menu and execution resumes.


When the program is terminated, the following message is printed:
```Text
-------------------------------------------
Thanks for using Seneca Library Application
```

## Tester program

[ms2_tester.cpp](MS2/ms2_tester.cpp)

### Data Entry
```Text
 1- 1
 2- 0
 3- 0
 4- 2
 5- 1
 6- 0
 7- 0
 8- 1
 9- 3
10- 1
11- 0
12- 1
13- 4
14- 0
15- 2
16- 0
17- 1
```

### output


# Milestone 3
## Streamable Interface module and Publication class module

## Types of publications in Seneca Library
Seneca Library holds two types of Publication; Periodical (like newspapers and Magazines) and Books. 

Publications are not loaned out to members. Members can check them out and read them in the library. These publications are put back on their shelves at the end of the day.

Books can be borrowed and returned within 15 days. After 15 days, the member will be charged daily for a late penalty.


# MS3 tester output
```Text
An Invalid publication printout:
><
Enter the following: 
P1234
------------------------------
Shelf No: P1234
Title: Date: You entered:
><
Enter the following: 
P123
Seneca Weekly
2023/13/17
------------------------------
Shelf No: P123
Title: Seneca Weekly
Date: 2023/13/17
You entered:
><
Enter the following: 
P123
Seneca Weekly
2023/11/17
------------------------------
Shelf No: P123
Title: Seneca Weekly
Date: 2023/11/17
You entered:
| P123 | Seneca Weekly................. |  N/A  | 2023/11/17 |
And the title is agian: "Seneca Weekly"
Now this publication is on loan to a member with the id: 12345
The checkout date is: 2023/12/25
The library unique reference id is: 9999
| P123 | Seneca Weekly................. | 12345 | 2023/12/25 |
----------------------------------------------------------------
Adding the periodical publication to the end of the data file:
appeneded to the file

Contents of the file:
|*   1*| P001 | The Toronto Star.............. | 34037 | 2023/11/17 |<<<
|*   2*| P001 | The Toronto Star.............. | 39710 | 2023/11/11 |<<<
|    3 | P001 | The Toronto Star.............. |  N/A  | 2023/11/24 |<<<
|*   4*| P001 | The Toronto Star.............. | 13059 | 2023/11/18 |<<<
|*   5*| P001 | The Toronto Star.............. | 61842 | 2023/11/17 |<<<
|    6 | P001 | The Toronto Star.............. |  N/A  | 2023/11/25 |<<<
|*   7*| P001 | The Toronto Star.............. | 26742 | 2023/11/18 |<<<
|*   8*| P001 | The Toronto Star.............. | 82938 | 2023/11/22 |<<<
|*   9*| P001 | The Toronto Star.............. | 68014 | 2023/11/15 |<<<
|   10 | P001 | The Toronto Star.............. |  N/A  | 2023/11/18 |<<<
|*  11*| P001 | The Toronto Star.............. | 42166 | 2023/11/23 |<<<
|*  12*| P001 | The Toronto Star.............. | 98201 | 2023/11/12 |<<<
|*  13*| P001 | The Toronto Star.............. | 34078 | 2023/11/12 |<<<
|   14 | P001 | The Toronto Star.............. |  N/A  | 2023/11/20 |<<<
|*  15*| P001 | The Toronto Star.............. | 86711 | 2023/11/16 |<<<
|*  16*| P001 | The Toronto Star.............. | 52095 | 2023/11/17 |<<<
|   17 | P001 | The Toronto Star.............. |  N/A  | 2023/11/17 |<<<
|*  18*| P001 | The Toronto Star.............. | 72323 | 2023/11/11 |<<<
|*  19*| P001 | The Toronto Star.............. | 81467 | 2023/11/24 |<<<
|*  20*| P001 | The Toronto Star.............. | 44322 | 2023/11/18 |<<<
|   21 | P001 | The Toronto Star.............. |  N/A  | 2023/11/17 |<<<
|*  22*| P001 | The Toronto Star.............. | 84453 | 2023/11/25 |<<<
|   23 | P001 | The Toronto Star.............. |  N/A  | 2023/11/18 |<<<
|*  24*| P001 | The Toronto Star.............. | 57952 | 2023/11/22 |<<<
|*  25*| P001 | The Toronto Star.............. | 65352 | 2023/11/15 |<<<
|*  26*| P001 | The Toronto Star.............. | 59731 | 2023/11/18 |<<<
|   27 | P001 | The Toronto Star.............. |  N/A  | 2023/11/23 |<<<
|*  28*| P001 | The Toronto Star.............. | 87403 | 2023/11/12 |<<<
|*  29*| P001 | The Toronto Star.............. | 63899 | 2023/11/12 |<<<
|   30 | P001 | The Toronto Star.............. |  N/A  | 2023/11/20 |<<<
|*  31*| P001 | The Toronto Star.............. | 34584 | 2023/11/16 |<<<
|   32 | P001 | The Toronto Star.............. |  N/A  | 2023/11/17 |<<<
|*  33*| P001 | The Toronto Star.............. | 23119 | 2023/11/17 |<<<
|*  34*| P001 | The Toronto Star.............. | 38659 | 2023/11/11 |<<<
|   35 | P001 | The Toronto Star.............. |  N/A  | 2023/11/24 |<<<
|*  36*| P001 | The Toronto Star.............. | 35869 | 2023/11/18 |<<<
|   37 | P001 | The Toronto Star.............. |  N/A  | 2023/11/17 |<<<
|*  38*| P001 | The Toronto Star.............. | 39753 | 2023/11/25 |<<<
|*  39*| P001 | The Toronto Star.............. | 26886 | 2023/11/18 |<<<
|*  40*| P001 | The Toronto Star.............. | 72671 | 2023/11/22 |<<<
|   41 | P001 | The Toronto Star.............. |  N/A  | 2023/11/15 |<<<
|*  42*| P001 | The Toronto Star.............. | 48156 | 2023/11/18 |<<<
|*  43*| P001 | The Toronto Star.............. | 92226 | 2023/11/23 |<<<
|*  44*| P001 | The Toronto Star.............. | 72803 | 2023/11/12 |<<<
|*  45*| P001 | The Toronto Star.............. | 47217 | 2023/11/12 |<<<
|   46 | P001 | The Toronto Star.............. |  N/A  | 2023/11/20 |<<<
|   47 | P001 | The Toronto Star.............. |  N/A  | 2023/11/16 |<<<
|*  48*| P001 | The Toronto Star.............. | 98926 | 2023/11/17 |<<<
|   49 | P001 | The Toronto Star.............. |  N/A  | 2023/11/17 |<<<
|*  50*| P004 | Hello! Canada Magazine........ | 89606 | 2023/11/11 |
|*  51*| P006 | Hello! Canada Magazine........ | 34087 | 2023/11/24 |
|*  52*| P006 | Hello! Canada Magazine........ | 91257 | 2023/11/18 |
|   53 | P006 | Hello! Canada Magazine........ |  N/A  | 2023/11/17 |
|*  54*| P006 | Hello! Canada Magazine........ | 15853 | 2023/11/25 |
|   55 | P006 | Hello! Canada Magazine........ |  N/A  | 2023/11/18 |
|*  56*| P006 | Hello! Canada Magazine........ | 77163 | 2023/11/22 |
|*  57*| P006 | Hello! Canada Magazine........ | 19525 | 2023/11/15 |
|*  58*| P006 | Hello! Canada Magazine........ | 80506 | 2023/11/18 |
|*  59*| P006 | Hello! Canada Magazine........ | 64345 | 2023/11/23 |
|*  60*| P006 | Hello! Canada Magazine........ | 63664 | 2023/11/12 |
|   61 | P006 | Hello! Canada Magazine........ |  N/A  | 2023/11/12 |
|*  62*| P006 | Hello! Canada Magazine........ | 83701 | 2023/11/20 |
|*  63*| P006 | Hello! Canada Magazine........ | 67334 | 2023/11/16 |
|*  64*| P007 | Macleans Magazine............. | 69613 | 2023/11/17 |
|*  65*| P007 | Macleans Magazine............. | 51529 | 2023/11/17 |
|   66 | P007 | Macleans Magazine............. |  N/A  | 2023/11/11 |
|*  67*| P007 | Macleans Magazine............. | 26730 | 2023/11/24 |
|*  68*| P007 | Macleans Magazine............. | 67044 | 2023/11/18 |
|*  69*| P007 | Macleans Magazine............. | 37529 | 2023/11/17 |
|   70 | P007 | Macleans Magazine............. |  N/A  | 2023/11/25 |
|*  71*| P007 | Macleans Magazine............. | 11246 | 2023/11/18 |
|*  72*| P007 | Macleans Magazine............. | 49225 | 2023/11/22 |
|   73 | P007 | Macleans Magazine............. |  N/A  | 2023/11/15 |
|*  74*| P007 | Macleans Magazine............. | 27658 | 2023/11/18 |
|*  75*| P007 | Macleans Magazine............. | 64706 | 2023/11/23 |
|*  76*| P007 | Macleans Magazine............. | 71447 | 2023/11/12 |
|*  77*| P007 | Macleans Magazine............. | 92433 | 2023/11/12 |
|   78 | P007 | Macleans Magazine............. |  N/A  | 2023/11/20 |
|*  79*| P008 | MoneySense Magazine........... | 72614 | 2023/11/16 |
|*  80*| P008 | MoneySense Magazine........... | 48096 | 2023/11/17 |
|*  81*| P008 | MoneySense Magazine........... | 89325 | 2023/11/17 |
|   82 | P008 | MoneySense Magazine........... |  N/A  | 2023/11/11 |
|*  83*| P008 | MoneySense Magazine........... | 70451 | 2023/11/24 |
|   84 | P008 | MoneySense Magazine........... |  N/A  | 2023/11/18 |
|*  85*| P008 | MoneySense Magazine........... | 33074 | 2023/11/17 |
|*  86*| P008 | Canadian Running Magazine..... | 77051 | 2023/11/25 |
|   87 | P008 | Canadian Running Magazine..... |  N/A  | 2023/11/18 |
|*  88*| P008 | Canadian Running Magazine..... | 86255 | 2023/11/22 |
|   89 | P008 | Canadian Running Magazine..... |  N/A  | 2023/11/15 |
|*  90*| P008 | Canadian Running Magazine..... | 46886 | 2023/11/18 |
|   91 | P008 | Canadian Running Magazine..... |  N/A  | 2023/11/23 |
|*  92*| P008 | Canadian Cycling Magazine..... | 21655 | 2023/11/12 |
|*  93*| P008 | Canadian Cycling Magazine..... | 64198 | 2023/11/12 |
|   94 | P008 | Canadian Cycling Magazine..... |  N/A  | 2023/11/20 |
|*  95*| P008 | Canadian Cycling Magazine..... | 53448 | 2023/11/16 |
|*  96*| P008 | Canadian Cycling Magazine..... | 59523 | 2023/11/17 |
|   97 | P008 | Canadian Cycling Magazine..... |  N/A  | 2023/11/17 |
|*  98*| P008 | Canadian Cycling Magazine..... | 40289 | 2023/11/11 |
|*  99*| P002 | The Toronto SUN............... | 85176 | 2023/11/17 |
|* 100*| P002 | The Toronto SUN............... | 28146 | 2023/11/11 |
|  101 | P002 | The Toronto SUN............... |  N/A  | 2023/11/24 |
|* 102*| P002 | The Toronto SUN............... | 23427 | 2023/11/18 |
|* 103*| P002 | The Toronto SUN............... | 22084 | 2023/11/17 |
|* 104*| P002 | The Toronto SUN............... | 63895 | 2023/11/25 |
|  105 | P002 | The Toronto SUN............... |  N/A  | 2023/11/18 |
|* 106*| P002 | The Toronto SUN............... | 85033 | 2023/11/22 |
|* 107*| P002 | The Toronto SUN............... | 21536 | 2023/11/15 |
|  108 | P002 | The Toronto SUN............... |  N/A  | 2023/11/18 |
|* 109*| P002 | The Toronto SUN............... | 39638 | 2023/11/23 |
|* 110*| P002 | The Toronto SUN............... | 63671 | 2023/11/12 |
|  111 | P002 | The Toronto SUN............... |  N/A  | 2023/11/12 |
|* 112*| P002 | The Toronto SUN............... | 44716 | 2023/11/20 |
|* 113*| P002 | The Toronto SUN............... | 58452 | 2023/11/16 |
|  114 | P002 | The Toronto SUN............... |  N/A  | 2023/11/17 |
|* 115*| P002 | The Toronto SUN............... | 67138 | 2023/11/17 |
|* 116*| P002 | The Toronto SUN............... | 58790 | 2023/11/11 |
|* 117*| P002 | The Toronto SUN............... | 71094 | 2023/11/24 |
|  118 | P002 | The Toronto SUN............... |  N/A  | 2023/11/18 |
|* 119*| P002 | The Toronto SUN............... | 91776 | 2023/11/17 |
|* 120*| P002 | The Toronto SUN............... | 60740 | 2023/11/25 |
|* 121*| P002 | The Toronto SUN............... | 33219 | 2023/11/18 |
|  122 | P002 | The Toronto SUN............... |  N/A  | 2023/11/22 |
|* 123*| P002 | The Toronto SUN............... | 45379 | 2023/11/15 |
|* 124*| P002 | The Toronto SUN............... | 12208 | 2023/11/18 |
|* 125*| P002 | The Toronto SUN............... | 36345 | 2023/11/23 |
|* 126*| P002 | The Toronto SUN............... | 42016 | 2023/11/12 |
|  127 | P002 | The Toronto SUN............... |  N/A  | 2023/11/12 |
|* 128*| P002 | The Toronto SUN............... | 92784 | 2023/11/20 |
|* 129*| P002 | The Toronto SUN............... | 41932 | 2023/11/16 |
|  130 | P002 | The Toronto SUN............... |  N/A  | 2023/11/17 |
|* 131*| P002 | The Toronto SUN............... | 62045 | 2023/11/17 |
|* 132*| P002 | The Toronto SUN............... | 21313 | 2023/11/11 |
|* 133*| P002 | The Toronto SUN............... | 46369 | 2023/11/24 |
|* 134*| P002 | The Toronto SUN............... | 56133 | 2023/11/18 |
|  135 | P002 | The Toronto SUN............... |  N/A  | 2023/11/17 |
|* 136*| P002 | The Toronto SUN............... | 84493 | 2023/11/25 |
|* 137*| P002 | The Toronto SUN............... | 64604 | 2023/11/18 |
|* 138*| P002 | The Toronto SUN............... | 58843 | 2023/11/22 |
|  139 | P002 | The Toronto SUN............... |  N/A  | 2023/11/15 |
|* 140*| P002 | The Toronto SUN............... | 21602 | 2023/11/18 |
|* 141*| P002 | The Toronto SUN............... | 81536 | 2023/11/23 |
|* 142*| P002 | The Toronto SUN............... | 43553 | 2023/11/12 |
|  143 | P002 | The Toronto SUN............... |  N/A  | 2023/11/12 |
|* 144*| P002 | The Toronto SUN............... | 86012 | 2023/11/20 |
|* 145*| P002 | The Toronto SUN............... | 26140 | 2023/11/16 |
|* 146*| P002 | The Toronto SUN............... | 63311 | 2023/11/17 |
|* 147*| P002 | The Toronto SUN............... | 74505 | 2023/11/17 |
|* 148*| P123 | Seneca Weekly................. | 12345 | 2023/12/25 |
```

# Milestone 4

## The **Book** class

This milestone will require the following modules and header files:
- Lib.h
- Uitls
- Date
- Streamable
- Publication

### The Book class implementation
The Book class is derived from the Publication class. A book is a publication with an "Author name". 
 
The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically. 


# MS4 Tester Program Output
```Text
An Invalid Book printout:
><

Enter the following: 
P1234
------------------------------
Shelf No: P1234
Title: Date: Author: You entered:
><

Enter the following: 
P123
Seneca Handbook
2023/13/17
------------------------------
Shelf No: P123
Title: Seneca Handbook
Date: 2023/13/17
Author: You entered:
><

Enter the following: 
P123
The Story of My Experiments with Truth
2023/11/17
Mohandas Karamchand Gandhi
------------------------------
Shelf No: P123
Title: The Story of My Experiments with Truth
Date: 2023/11/17
Author: Mohandas Karamchand Gandhi
You entered:
| P123 | The Story of My Experiments wi |  N/A  | 2023/11/17 | Mohandas Karamc |
And the title is agian: "The Story of My Experiments with Truth"
Now this publication is on loan to a member with the id: 12345
The checkout date is: 2023/12/25
The library unique reference id is: 9999
| P123 | The Story of My Experiments wi | 12345 | 2023/12/25 | Mohandas Karamc |
----------------------------------------------------------------
Adding the Book to the end of the data file:
appeneded to the file

Contents of the file:
|*   1*| C544 | The Hobbit.................... | 35277 | 2023/11/14 | J. R. R. Tolkie |
|*   2*| D208 | Harry Potter and the Philosoph | 72685 | 2023/11/19 | J. K. Rowling   |
|*   3*| N576 | The Little Prince............. | 96745 | 2023/11/19 | Antoine de Sain |
|*   4*| R420 | Dream of the Red Chamber...... | 87691 | 2023/11/24 | Cao Xueqin      |
|*   5*| R393 | And Then There Were None...... | 35526 | 2023/11/12 | Agatha Christie |
|    6 | P380 | The Lion/ the Witch and the Wa |  N/A  | 2023/11/18 | C. S. Lewis     |
|    7 | U264 | She: A History of Adventure... |  N/A  | 2023/11/11 | H. Rider Haggar |
|    8 | S945 | The Adventures of Pinocchio... |  N/A  | 2023/11/18 | Carlo Collodi   |
|    9 | U818 | The Da Vinci Code............. |  N/A  | 2023/11/19 | Dan Brown       |
|   10 | F861 | Harry Potter and the Chamber o |  N/A  | 2023/11/24 | J. K. Rowling   |
|   11 | R856 | Harry Potter and the Prisoner  |  N/A  | 2023/11/10 | J. K. Rowling   |
|   12 | C945 | Harry Potter and the Goblet of |  N/A  | 2023/11/14 | J. K. Rowling   |
|   13 | L290 | Harry Potter and the Order of  |  N/A  | 2023/11/11 | J. K. Rowling   |
|*  14*| C332 | Harry Potter and the Half/Bloo | 85952 | 2023/11/22 | J. K. Rowling   |
|*  15*| C872 | Harry Potter and the Deathly H | 64984 | 2023/11/17 | J. K. Rowling   |
|*  16*| Y686 | The Alchemist................. | 63288 | 2023/11/10 | Paulo Coelho    |
|*  17*| E147 | The Catcher in the Rye........ | 90607 | 2023/11/19 | J. D. Salinger  |
|*  18*| N518 | The Bridges of Madison County. | 15467 | 2023/11/14 | Robert James Wa |
|*  19*| U215 | Ben/Hur: A Tale of the Christ. | 71498 | 2023/11/19 | Lew Wallace     |
|*  20*| L200 | You Can Heal Your Life........ | 33507 | 2023/11/18 | Louise Hay      |
|*  21*| W571 | One Hundred Years of Solitude. | 14022 | 2023/11/24 | Gabriel Garca M |
|*  22*| E655 | Lolita........................ | 96706 | 2023/11/22 | Vladimir Naboko |
|*  23*| J846 | Heidi......................... | 16990 | 2023/11/23 | Johanna Spyri   |
|*  24*| E869 | The Common Sense Book of Baby  | 80854 | 2023/11/24 | Benjamin Spock  |
|*  25*| L667 | Anne of Green Gables.......... | 51189 | 2023/11/24 | Lucy Maud Montg |
|*  26*| Y627 | Black Beauty.................. | 43657 | 2023/11/18 | Anna Sewell     |
|*  27*| D619 | The Name of the Rose.......... | 22397 | 2023/11/10 | Umberto Eco     |
|   28 | N537 | The Eagle Has Landed.......... |  N/A  | 2023/11/16 | Jack Higgins    |
|   29 | H405 | Watership Down................ |  N/A  | 2023/11/23 | Richard Adams   |
|   30 | H859 | The Hite Report............... |  N/A  | 2023/11/13 | Shere Hite      |
|   31 | Z192 | Charlotte's Web............... |  N/A  | 2023/11/17 | E. B. White; il |
|   32 | V718 | The Tale of Peter Rabbit...... |  N/A  | 2023/11/12 | Beatrix Potter  |
|   33 | Z248 | Jonathan Livingston Seagull... |  N/A  | 2023/11/21 | Richard Bach    |
|   34 | B236 | The Very Hungry Caterpillar... |  N/A  | 2023/11/12 | Eric Carle      |
|   35 | T223 | A Message to Garcia........... |  N/A  | 2023/11/24 | Elbert Hubbard  |
|*  36*| U846 | To Kill a Mockingbird......... | 45511 | 2023/11/21 | Harper Lee      |
|*  37*| F676 | Flowers in the Attic.......... | 85381 | 2023/11/14 | V. C. Andrews   |
|*  38*| Q353 | Cosmos........................ | 33904 | 2023/11/19 | Carl Sagan      |
|*  39*| U737 | Sophie's World................ | 60897 | 2023/11/12 | Jostein Gaarder |
|*  40*| T273 | Angels & Demons............... | 51481 | 2023/11/22 | Dan Brown       |
|*  41*| M309 | Kane and Abel................. | 82568 | 2023/11/19 | Jeffrey Archer  |
|*  42*| J579 | How the Steel Was Tempered.... | 34668 | 2023/11/17 | Nikolai Ostrovs |
|   43 | I325 | War and Peace................. |  N/A  | 2023/11/24 | Leo Tolstoy     |
|   44 | B663 | The Diary of Anne Frank....... |  N/A  | 2023/11/22 | Anne Frank      |
|   45 | M760 | Your Erroneous Zones.......... |  N/A  | 2023/11/13 | Wayne Dyer      |
|   46 | W525 | The Thorn Birds............... |  N/A  | 2023/11/14 | Colleen McCullo |
|   47 | Z305 | The Purpose Driven Life....... |  N/A  | 2023/11/19 | Rick Warren     |
|   48 | F282 | The Kite Runner............... |  N/A  | 2023/11/11 | Khaled Hosseini |
|   49 | L141 | Valley of the Dolls........... |  N/A  | 2023/11/20 | Jacqueline Susa |
|   50 | V843 | The Great Gatsby.............. |  N/A  | 2023/11/24 | F. Scott Fitzge |
|*  51*| Z611 | Gone with the Wind............ | 95732 | 2023/11/25 | Margaret Mitche |
|*  52*| Q378 | Rebecca....................... | 66619 | 2023/11/11 | Daphne du Mauri |
|*  53*| M413 | Nineteen Eighty/Four.......... | 34208 | 2023/11/17 | George Orwell   |
|*  54*| K496 | The Revolt of Mamie Stover.... | 53331 | 2023/11/25 | William Bradfor |
|*  55*| J587 | The Girl with the Dragon Tatto | 17660 | 2023/11/17 | Stieg Larsson   |
|*  56*| O930 | The Lost Symbol............... | 51773 | 2023/11/21 | Dan Brown       |
|*  57*| D427 | The Hunger Games.............. | 52280 | 2023/11/23 | Suzanne Collins |
|   58 | S924 | James and the Giant Peach..... |  N/A  | 2023/11/22 | Roald Dahl      |
|   59 | E662 | The Young Guard............... |  N/A  | 2023/11/17 | Alexander Alexa |
|   60 | E866 | Who Moved My Cheese?.......... |  N/A  | 2023/11/10 | Spencer Johnson |
|   61 | Q413 | A Brief History of Time....... |  N/A  | 2023/11/18 | Stephen Hawking |
|   62 | N114 | Paul et Virginie.............. |  N/A  | 2023/11/17 | Jacques/Henri B |
|   63 | O655 | Lust for Life................. |  N/A  | 2023/11/16 | Irving Stone    |
|   64 | W675 | The Wind in the Willows....... |  N/A  | 2023/11/20 | Kenneth Grahame |
|   65 | K349 | The 7 Habits of Highly Effecti |  N/A  | 2023/11/18 | Stephen R. Cove |
|*  66*| Q968 | Virgin Soil Upturned.......... | 46394 | 2023/11/18 | Mikhail Sholokh |
|*  67*| Y690 | The Celestine Prophecy........ | 88238 | 2023/11/16 | James Redfield  |
|*  68*| L480 | The Fault in Our Stars........ | 31647 | 2023/11/12 | John Green      |<<<
|*  69*| V829 | The Girl on the Train......... | 26056 | 2023/11/14 | Paula Hawkins   |
|*  70*| K360 | The Shack..................... | 20029 | 2023/11/18 | William P. Youn |
|*  71*| O701 | Uncle Styopa.................. | 73994 | 2023/11/18 | Sergey Mikhalko |
|*  72*| Y150 | The Godfather................. | 14732 | 2023/11/11 | Mario Puzo      |
|*  73*| I780 | Love Story.................... | 46975 | 2023/11/23 | Erich Segal     |
|   74 | J808 | Catching Fire................. |  N/A  | 2023/11/13 | Suzanne Collins |
|   75 | X943 | Mockingjay.................... |  N/A  | 2023/11/21 | Suzanne Collins |
|   76 | Y443 | Kitchen....................... |  N/A  | 2023/11/24 | Banana Yoshimot |
|   77 | H141 | Andromeda Nebula.............. |  N/A  | 2023/11/17 | Ivan Yefremov   |
|   78 | E807 | Autobiography of a Yogi....... |  N/A  | 2023/11/18 | Paramahansa Yog |
|   79 | D556 | Gone Girl..................... |  N/A  | 2023/11/12 | Gillian Flynn   |
|   80 | L261 | All Quiet on the Western Front |  N/A  | 2023/11/23 | Erich Maria Rem |
|   81 | Y409 | The Bermuda Triangle.......... |  N/A  | 2023/11/19 | Charles Berlitz |
|*  82*| W818 | Things Fall Apart............. | 20217 | 2023/11/13 | Chinua Achebe   |
|*  83*| C787 | Animal Farm................... | 11826 | 2023/11/12 | George Orwell   |
|*  84*| S458 | Wolf Totem.................... | 36783 | 2023/11/25 | Jiang Rong      |
|*  85*| T202 | The Happy Hooker: My Own Story | 94024 | 2023/11/14 | Xaviera Holland |
|*  86*| K964 | Jaws.......................... | 97818 | 2023/11/23 | Peter Benchley  |
|*  87*| D159 | Love You Forever.............. | 50828 | 2023/11/19 | Robert Munsch   |
|*  88*| L671 | The Women's Room.............. | 17950 | 2023/11/17 | Marilyn French  |
|   89 | K161 | What to Expect When You're Exp |  N/A  | 2023/11/20 | Arlene Eisenber |
|   90 | N299 | Adventures of Huckleberry Finn |  N/A  | 2023/11/16 | Mark Twain      |
|   91 | K215 | The Secret Diary of Adrian Mol |  N/A  | 2023/11/22 | Sue Townsend    |
|   92 | Y397 | Pride and Prejudice........... |  N/A  | 2023/11/21 | Jane Austen     |
|   93 | R741 | Kon/Tiki: Across the Pacific i |  N/A  | 2023/11/23 | Thor Heyerdahl  |
|   94 | C629 | The Good Soldier Svejk........ |  N/A  | 2023/11/17 | Jaroslav Hasek  |
|   95 | N157 | Where the Wild Things Are..... |  N/A  | 2023/11/22 | Maurice Sendak  |
|   96 | I973 | The Power of Positive Thinking |  N/A  | 2023/11/16 | Norman Vincent  |
|*  97*| L645 | The Secret.................... | 27720 | 2023/11/17 | Rhonda Byrne    |
|*  98*| B320 | Fear of Flying................ | 77938 | 2023/11/24 | Erica Jong      |
|*  99*| K887 | Dune.......................... | 25982 | 2023/11/11 | Frank Herbert   |
|* 100*| H138 | Charlie and the Chocolate Fact | 39496 | 2023/11/18 | Roald Dahl      |
|* 101*| P508 | The Naked Ape................. | 42832 | 2023/11/22 | Desmond Morris  |
|* 102*| W726 | Totto/chan/ the Little Girl at | 69687 | 2023/11/19 | Tetsuko Kuroyan |
|  103 | L207 | Matilda....................... |  N/A  | 2023/11/15 | Roald Dahl      |
|  104 | O898 | The Book Thief................ |  N/A  | 2023/11/23 | Markus Zusak    |
|  105 | S595 | The Horse Whisperer........... |  N/A  | 2023/11/23 | Nicholas Evans  |
|  106 | O807 | Goodnight Moon................ |  N/A  | 2023/11/24 | Margaret Wise B |
|  107 | U823 | The Neverending Story......... |  N/A  | 2023/11/22 | Michael Ende    |
|  108 | S159 | Fifty Shades of Grey.......... |  N/A  | 2023/11/21 | E. L. James     |
|  109 | M201 | The Outsiders................. |  N/A  | 2023/11/13 | S. E. Hinton    |
|  110 | H423 | Guess How Much I Love You..... |  N/A  | 2023/11/22 | Sam McBratney   |
|* 111*| G743 | Sh?gun........................ | 85725 | 2023/11/18 | James Clavell   |
|* 112*| K764 | The Poky Little Puppy......... | 71507 | 2023/11/24 | Janette Sebring |
|* 113*| Z222 | The Pillars of the Earth...... | 30945 | 2023/11/17 | Ken Follett     |
|* 114*| D650 | How to Win Friends and Influen | 35147 | 2023/11/17 | Dale Carnegie   |
|* 115*| Y296 | Perfume....................... | 83613 | 2023/11/15 | Patrick Sskind  |
|* 116*| O754 | The Grapes of Wrath........... | 98504 | 2023/11/17 | John Steinbeck  |
|* 117*| L111 | The Shadow of the Wind........ | 46030 | 2023/11/15 | Carlos Ruiz Zaf |
|* 118*| L954 | Interpreter of Maladies....... | 13591 | 2023/11/14 | Jhumpa Lahiri   |
|* 119*| Y471 | Becoming...................... | 53305 | 2023/11/20 | Michelle Obama  |
|* 120*| U633 | The Hitchhiker's Guide to the  | 32505 | 2023/11/17 | Douglas Adams   |
|  121 | W733 | Tuesdays with Morrie.......... |  N/A  | 2023/11/18 | Mitch Albom     |
|  122 | J278 | God's Little Acre............. |  N/A  | 2023/11/14 | Erskine Caldwel |
|  123 | M576 | Follow Your Heart............. |  N/A  | 2023/11/24 | Susanna Tamaro  |
|  124 | Z409 | A Wrinkle in Time............. |  N/A  | 2023/11/22 | Madeleine L'Eng |
|  125 | F213 | Long Walk to Freedom.......... |  N/A  | 2023/11/16 | Nelson Mandela  |
|  126 | Q183 | The Old Man and the Sea....... |  N/A  | 2023/11/23 | Ernest Hemingwa |
|  127 | V418 | Life After Life............... |  N/A  | 2023/11/21 | Raymond Moody   |
|  128 | O117 | Me Before You................. |  N/A  | 2023/11/15 | Jojo Moyes      |
|* 129*| M852 | Norwegian Wood................ | 44911 | 2023/11/22 | Haruki Murakami |
|* 130*| U158 | Peyton Place.................. | 49730 | 2023/11/19 | Grace Metalious |
|* 131*| Y966 | The Plague.................... | 28406 | 2023/11/24 | Albert Camus    |
|* 132*| T555 | No Longer Human............... | 15056 | 2023/11/13 | Osamu Dazai     |
|* 133*| P459 | Man's Search for Meaning...... | 87325 | 2023/11/20 | Viktor Frankl   |
|* 134*| S478 | The Divine Comedy............. | 37489 | 2023/11/15 | Dante Alighieri |
|* 135*| O151 | The Prophet................... | 66378 | 2023/11/16 | Kahlil Gibran   |
|* 136*| G990 | The Exorcist.................. | 91012 | 2023/11/23 | William Peter B |
|* 137*| X564 | The Gruffalo.................. | 76377 | 2023/11/19 | Julia Donaldson |
|* 138*| R558 | Fifty Shades Darker........... | 22675 | 2023/11/18 | E. L. James     |
|  139 | O741 | Ronia/ the Robber's Daughter.. |  N/A  | 2023/11/21 | Astrid Lindgren |
|  140 | I551 | The Cat in the Hat............ |  N/A  | 2023/11/22 | Dr. Seuss       |
|  141 | V392 | Diana: Her True Story......... |  N/A  | 2023/11/23 | Andrew Morton   |
|  142 | L677 | The Help...................... |  N/A  | 2023/11/12 | Kathryn Stocket |
|  143 | U200 | Catch/22...................... |  N/A  | 2023/11/15 | Joseph Heller   |
|  144 | V547 | The Stranger.................. |  N/A  | 2023/11/16 | Albert Camus    |
|  145 | T740 | Eye of the Needle............. |  N/A  | 2023/11/10 | Ken Follett     |
|  146 | G142 | The Lovely Bones.............. |  N/A  | 2023/11/22 | Alice Sebold    |
|* 147*| I769 | Wild Swans.................... | 32345 | 2023/11/23 | Jung Chang      |
|* 148*| F333 | Santa Evita................... | 54099 | 2023/11/23 | Toms Eloy Martn |
|* 149*| X737 | Night......................... | 88228 | 2023/11/22 | Elie Wiesel     |
|* 150*| Y316 | Confucius from the Heart...... | 24780 | 2023/11/18 | Yu Dan          |
|* 151*| T262 | The Total Woman............... | 68109 | 2023/11/14 | Marabel Morgan  |
|* 152*| W401 | Knowledge/value Revolution.... | 69282 | 2023/11/16 | Taichi Sakaiya  |
|* 153*| V594 | Problems in China's Socialist  | 97800 | 2023/11/25 | Xue Muqiao      |
|* 154*| E106 | What Color Is Your Parachute?. | 33009 | 2023/11/20 | Richard Nelson  |
|* 155*| J633 | The Dukan Diet................ | 29260 | 2023/11/20 | Pierre Dukan    |
|  156 | C194 | The Joy of Sex................ |  N/A  | 2023/11/21 | Alex Comfort    |
|  157 | M791 | The Gospel According to Peanut |  N/A  | 2023/11/18 | Robert L. Short |
|  158 | V105 | Life of Pi.................... |  N/A  | 2023/11/15 | Yann Martel     |
|  159 | W580 | The Giver..................... |  N/A  | 2023/11/14 | Lois Lowry      |
|  160 | N950 | The Front Runner.............. |  N/A  | 2023/11/17 | Patricia Nell W |
|  161 | D951 | The Goal...................... |  N/A  | 2023/11/18 | Eliyahu M. Gold |
|  162 | P605 | Fahrenheit 451................ |  N/A  | 2023/11/12 | Ray Bradbury    |
|  163 | N368 | Angela's Ashes................ |  N/A  | 2023/11/11 | Frank McCourt   |
|* 164*| T113 | The Story of My Experiments wi | 59505 | 2023/11/10 | Mohandas Karamc |
|* 165*| T506 | Bridget Jones's Diary......... | 69410 | 2023/11/17 | Helen Fielding  |
|* 166*| T343 | Harry Potter.................. | 65205 | 2023/11/19 | J. K. Rowling   |
|* 167*| F311 | Goosebumps.................... | 17539 | 2023/11/10 | R. L. Stine     |
|* 168*| Y690 | Perry Mason................... | 28218 | 2023/11/15 | Erle Stanley Ga |
|* 169*| K460 | Berenstain Bears.............. | 78200 | 2023/11/12 | Stan and Jan Be |
|* 170*| M671 | Choose Your Own Adventure..... | 27792 | 2023/11/25 | Various authors |
|* 171*| P727 | Diary of a Wimpy Kid.......... | 91885 | 2023/11/22 | Jeff Kinney     |
|* 172*| X982 | Sweet Valley High............. | 74095 | 2023/11/25 | Francine Pascal |
|* 173*| S868 | Noddy......................... | 19857 | 2023/11/24 | Enid Blyton     |
|* 174*| D155 | Nancy Drew.................... | 28526 | 2023/11/15 | Various authors |
|* 175*| K424 | The Railway Series............ | 75067 | 2023/11/13 | Rev. W. Awdry/C |
|* 176*| Y569 | San/Antonio................... | 21794 | 2023/11/13 | Frdric Dard     |
|  177 | M813 | Robert Langdon................ |  N/A  | 2023/11/10 | Dan Brown       |
|  178 | Q779 | The Baby/sitters Club......... |  N/A  | 2023/11/21 | Ann Martin      |
|  179 | Y951 | Twilight...................... |  N/A  | 2023/11/25 | Stephenie Meyer |
|  180 | B974 | Star Wars..................... |  N/A  | 2023/11/18 | Various authors |<<<
|  181 | C663 | Little Critter................ |  N/A  | 2023/11/11 | Mercer Mayer    |
|  182 | B953 | Peter Rabbit.................. |  N/A  | 2023/11/17 | Beatrix Potter  |
|  183 | I318 | Fifty Shades.................. |  N/A  | 2023/11/12 | E. L. James     |
|  184 | V353 | American Girl................. |  N/A  | 2023/11/20 | Various authors |
|* 185*| O485 | Geronimo Stilton.............. | 62861 | 2023/11/24 | Elisabetta Dami |
|* 186*| M996 | Chicken Soup for the Soul..... | 37949 | 2023/11/21 | Jack Canfield/M |
|* 187*| K954 | Clifford the Big Red Dog...... | 73358 | 2023/11/21 | Norman Bridwell |
|* 188*| I715 | Frank Merriwell............... | 78859 | 2023/11/11 | Gilbert Patten  |
|* 189*| D848 | Dirk Pitt..................... | 13282 | 2023/11/23 | Clive Cussler   |
|* 190*| L724 | Musashi....................... | 74367 | 2023/11/25 | Eiji Yoshikawa  |
|* 191*| P734 | The Chronicles of Narnia...... | 16623 | 2023/11/20 | C. S. Lewis     |
|* 192*| D855 | Mr. Men....................... | 39972 | 2023/11/10 | Roger Hargreave |
|* 193*| H554 | The Hunger Games trilogy...... | 30930 | 2023/11/13 | Suzanne Collins |
|* 194*| U134 | James Bond.................... | 12755 | 2023/11/23 | Ian Fleming     |
|* 195*| V363 | Martine....................... | 95794 | 2023/11/19 | Gilbert Delahay |
|* 196*| T956 | Millennium.................... | 32418 | 2023/11/17 | Stieg Larsson/D |
|* 197*| C902 | A Song of Ice and Fire........ | 13881 | 2023/11/17 | George R. R. Ma |
|  198 | U820 | Discworld..................... |  N/A  | 2023/11/16 | Terry Pratchett |
|  199 | R242 | Nijntje....................... |  N/A  | 2023/11/11 | Dick Bruna      |
|  200 | W452 | Alex Cross.................... |  N/A  | 2023/11/25 | James Patterson |
|  201 | R141 | Anpanman...................... |  N/A  | 2023/11/15 | Takashi Yanase  |
|  202 | E505 | Captain Underpants............ |  N/A  | 2023/11/22 | Dav Pilkey      |
|  203 | D307 | Fear Street................... |  N/A  | 2023/11/24 | R. L. Stine     |
|  204 | P601 | Pippi Longstocking............ |  N/A  | 2023/11/17 | Astrid Lindgren |
|  205 | Z256 | The Vampire Chronicles........ |  N/A  | 2023/11/11 | Anne Rice       |
|* 206*| P888 | The Wheel of Time............. | 47315 | 2023/11/24 | Robert Jordan/B |
|* 207*| O220 | OSS 117....................... | 74391 | 2023/11/18 | Jean Bruce      |
|* 208*| O514 | Winnie/the/Pooh............... | 86764 | 2023/11/17 | A. A. Milne; il |
|* 209*| W758 | Magic Tree House series....... | 38222 | 2023/11/25 | Mary Pope Osbor |
|* 210*| W722 | Left Behind................... | 18232 | 2023/11/18 | Tim LaHaye/Jerr |
|* 211*| U147 | A Series of Unfortunate Events | 47436 | 2023/11/22 | Lemony Snicketa |
|* 212*| L222 | Little House on the Prairie... | 98737 | 2023/11/15 | Laura Ingalls W |
|* 213*| P604 | Jack Reacher.................. | 30467 | 2023/11/18 | Lee Child       |
|* 214*| F365 | The Magic School Bus.......... | 34077 | 2023/11/23 | Joanna Cole/ il |
|* 215*| P307 | Where's Wally?................ | 11089 | 2023/11/12 | Martin Handford |
|* 216*| Y853 | Men Are from Mars/ Women Are f | 98905 | 2023/11/12 | John Gray       |
|* 217*| C631 | The Hardy Boys................ | 42472 | 2023/11/20 | Various authors |
|* 218*| M406 | The Bobbsey Twins............. | 37365 | 2023/11/16 | Various authors |
|* 219*| V259 | Tarzan........................ | 76029 | 2023/11/17 | Edgar Rice Burr |
|* 220*| P123 | The Story of My Experiments wi | 12345 | 2023/12/25 | Mohandas Karamc |
```

# Milestone 5
## The Seneca Library Application

### PublicationSelector Module

The PublicationSelector module holds the addresses of a selection of the Publications in an array and lets the user select one of them. Upon user's selection, the Library Reference number of the selected publication is returned to the caller module for further actions. 

For example, the array of Publications can be searched for a match to a specific title, and the matches found in the array can be inserted into the PublicationSelector. 
Then the PublicationSelector can be run to display the search results and ask the user to select one of them.  




