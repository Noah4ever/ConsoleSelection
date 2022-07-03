# ConsoleSelection

https://user-images.githubusercontent.com/66632359/177047134-c1590308-522c-4bcc-ac76-29ac69d07f4c.mp4

## How to use:
1. include header file: 
```
include "Selection.h"
```
2. Create vector and add options:
```
std::vector<SelectionOption> options;
options.push_back(SelectionOption("Option 1"));
options.push_back(SelectionOption("Option 2"));
options.push_back(SelectionOption("Option 3"));
```
![image](https://user-images.githubusercontent.com/66632359/177047264-a7379070-5ae2-41b2-a33a-d0519716d18a.png)

3. Create Selection object with options:
```
Selection selection = Selection(options);
```
4. Set prefix and suffix for selected option:
  - First value: prefix
  - Second value: suffix
```
selection.setPrefixSuffix("--[ ", " ]--");
```
![image](https://user-images.githubusercontent.com/66632359/177047293-b31bd806-a9f5-49e6-9b1a-38966531cdf9.png)

5. Set text and background colors:
   - First value: text color
   - Second value: selected option text color
   - Third value: text background
   - Forth value: selected option text background
```
selection.setColors("white", "red", "none", "none");	
```
![image](https://user-images.githubusercontent.com/66632359/177047305-61b9a5b0-e5f1-4bdf-affe-1983f185fbd1.png)

6. Start selection. Return value is the selected index:
```
int index = selection.Start();
```
- To move selection down press: 's' or 'down arrow key'
- To move selection up press: 'w' or 'up arrow key'
- To confirm selection press: 'enter' or 'spacebar'

## Code
1. Some methods:
![image](https://user-images.githubusercontent.com/66632359/177047622-705960b3-b85d-4d58-9f3a-ec3d7997c25c.png)


