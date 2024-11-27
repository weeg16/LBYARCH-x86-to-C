# LBYARCH-x86-to-C
LBYARCH - S16 - MP2-Group 11

Robles, Luis Miguel

Quiambao, Mark Kobe

# 

Task: Implement a program that converts the grayscale image representation from int based to float based using C and x86 assembly language. Implement the function imgCvtGrayInttoFloat().

## AVERAGE EXECUTION TIMES 

- 10 * 10 = 750ns

- 100 * 100 = 78,807ns

- 500 * 500 = 917,780ns

Each size was tested 30 times each, with the following results generated.

## ANALYSIS
- 750ns/100 = 7.5ns per pixel
- 78,807/10,000 = 7.88ns per pixel
- 917,780/250,000 = 3.67ns per pixel
  
The ASM function was efficient and scaled linearly throughout different input sizes. The average time per pixel confirmed that its performance was optimized for converting integer-based grayscale images into floating point representations.

## SAMPLES

- 10 * 10
![Screenshot 2024-11-27 230040](https://github.com/user-attachments/assets/1fd1f66d-4507-4473-badf-e9bc0615239a)

- 100 * 100
![image](https://github.com/user-attachments/assets/ccd63da0-fffa-4ee1-b455-fb74f6634dd6)

- 500 * 500
![image](https://github.com/user-attachments/assets/53a56284-a308-4774-8b4d-6a617daca297)

