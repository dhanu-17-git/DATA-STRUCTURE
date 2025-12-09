

---

# 🧱 **DARSHAN V — STRUCT + HELPERS + FILE OPEN**

## 🧠 Concept Explanation

* 📦 We are storing **year, month, day, temp, humidity, rain** per day.
* 🏗️ Using a **struct** groups all this into one object instead of separate messy arrays.
* 🔢 `dateToNumber()` converts `YYYY-MM-DD` → **20250105**, which makes comparing dates EASY.
* 🔡 `toLowerStr()` converts any input → lowercase for **case-insensitive** handling.
* 📅 `getMonthNumber()` converts `"1"`, `"01"`, `"jan"`, `"January"` → **1**.
* 📂 File is dynamic: location `"Mysore"` → opens `"Mysore.txt"`.

---

## 🔢 Code (Helpers + Struct)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int year, month, day;
    float temp;
    float humidity;
    int rain;   // 1 = rainy day, 0 = no rain
} Weather;

int dateToNumber(int y, int m, int d) {
    return y * 10000 + m * 100 + d; // e.g., 2025,1,5 -> 20250105
}

// Convert string to lowercase (in-place)
void toLowerStr(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (char)tolower((unsigned char)s[i]);
    }
}

// Map month input ("1", "01", "jan", "january") -> month number 1-12
int getMonthNumber(const char *input) {
    char buf[20];
    strncpy(buf, input, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    toLowerStr(buf);

    // If all digits, treat as month number
    int allDigits = 1;
    for (int i = 0; buf[i] != '\0'; i++) {
        if (!isdigit((unsigned char)buf[i])) {
            allDigits = 0;
            break;
        }
    }

    if (allDigits) {
        int m = atoi(buf);
        if (m >= 1 && m <= 12)
            return m;
        else
            return -1;
    }

    // Check by name (first 3 letters are enough)
    if (strncmp(buf, "jan", 3) == 0) return 1;
    if (strncmp(buf, "feb", 3) == 0) return 2;
    if (strncmp(buf, "mar", 3) == 0) return 3;
    if (strncmp(buf, "apr", 3) == 0) return 4;
    if (strncmp(buf, "may", 3) == 0) return 5;
    if (strncmp(buf, "jun", 3) == 0) return 6;
    if (strncmp(buf, "jul", 3) == 0) return 7;
    if (strncmp(buf, "aug", 3) == 0) return 8;
    if (strncmp(buf, "sep", 3) == 0) return 9;
    if (strncmp(buf, "oct", 3) == 0) return 10;
    if (strncmp(buf, "nov", 3) == 0) return 11;
    if (strncmp(buf, "dec", 3) == 0) return 12;

    return -1;  // invalid month string
}
```

---

## ❓ Teacher Might Ask You — WITH Answers

### **1️⃣ Why did you use a struct instead of separate arrays?**

👉 Struct keeps all related data of ONE day in ONE place → avoids chaos of parallel arrays.

### **2️⃣ What is the advantage of `dateToNumber()`?**

👉 Makes comparing two dates easy using simple integer `< > <= >=`.

### **3️⃣ Why do you convert month input to lowercase?**

👉 To handle JAN / jan / JaNuArY all the same → standardized.

### **4️⃣ How do you handle Jan vs January vs 1?**

👉 Convert to lowercase → check digits → else first 3 letters.

### **5️⃣ What happens if the file doesn’t exist?**

👉 Program prints error and exits safely.

---

# 🧍 **MEMBER 2 — MONTH INPUT + YEAR + RANGE LOGIC (FULL + FIXED)**

## 🧠 Concept Explanation

* User can type month like: `1`, `01`, `Jan`, `JAN`, `January`.
* `getMonthNumber()` unifies all these → month number.
* Year taken separately to avoid confusion.
* Ask user if they want **date range** inside the month.
* Full month is default (1 to 31).
* If reversed input (25 → 10), we automatically **swap**.
* Convert from/to dates into single number for easy comparison.

---

## 🔢 Code You Own (INCLUDING MISSED `main()` PART)

```c
int main() {

    char location[50], filename[60];
    char monthInput[20];
    int inputMonth, inputYear;

    const char *monthNames[] = {
        "",
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    printf("Enter location: ");
    scanf("%49s", location);

    sprintf(filename, "%s.txt", location);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Cannot open file %s\n", filename);
        printf("Make sure the file exists in the current directory.\n");
        return 1;
    }

    // ------------ MEMBER 2 code starts ------------

    printf("Enter Month (number or name, e.g., 1 or Jan or January): ");
    scanf("%19s", monthInput);

    inputMonth = getMonthNumber(monthInput);
    if (inputMonth == -1) {
        printf("Invalid month input. Please use 1-12 or names like Jan/January.\n");
        fclose(fp);
        return 1;
    }

    printf("Enter Year: ");
    scanf("%d", &inputYear);
    
    // ADD: Year validation
    if (inputYear < 1900 || inputYear > 2100) {
        printf("Invalid year. Please enter a year between 1900-2100.\n");
        fclose(fp);
        return 1;
    }

    char choice[10];
    int useRange = 0;

    printf("Do you want a date range inside this month? (yes/no): ");
    scanf("%9s", choice);
    toLowerStr(choice);

    if (strcmp(choice, "yes") == 0 || strcmp(choice, "y") == 0) {
        useRange = 1;
    }

    int fromDay = 1, toDay = 31;

    if (useRange) {
        printf("Enter FROM day (1-31): ");
        scanf("%d", &fromDay);
        
        // ADD: Day validation
        if (fromDay < 1 || fromDay > 31) {
            printf("Invalid day. Must be between 1-31.\n");
            fclose(fp);
            return 1;
        }

        printf("Enter TO day (1-31): ");
        scanf("%d", &toDay);
        
        // ADD: Day validation
        if (toDay < 1 || toDay > 31) {
            printf("Invalid day. Must be between 1-31.\n");
            fclose(fp);
            return 1;
        }

        if (fromDay > toDay) {
            int temp = fromDay;
            fromDay = toDay;
            toDay = temp;
        }
    }

    int fromNum = dateToNumber(inputYear, inputMonth, fromDay);
    int toNum   = dateToNumber(inputYear, inputMonth, toDay);
```

---

## ❓ Teacher Might Ask You — WITH Answers

### **1️⃣ Why is the flow "month → year → range"?**

👉 User naturally chooses month & year first; range is optional detail after.

### **2️⃣ How do you handle Feb/february?**

👉 Input is lowercased → `"feb"` automatically mapped → **2**.

### **3️⃣ Why swap fromDay & toDay?**

👉 If user gives 28 → 10, swapping ensures valid range.

### **4️⃣ Why default full month (1–31)?**

👉 So even if user chooses no range, we still read entire month.

### **5️⃣ Why convert date to `YYYYMMDD` integer?**

👉 Comparing 20250110 < 20250125 is easier than checking year/month/day separately.

---

# 💻 **DEEKSHITH — FILE READ + FILTERING**

## 🧠 Concept Explanation

* Prepare accumulators for averages and tracking extremes.
* Track dates of max/min temp and humidity.
* Rainy dates stored in an array.
* Read each line using `fscanf`.
* Parse date from string.
* Apply filters based on month/year/range.

---

## 🔢 Code

```c
    float tempTotal = 0, humidTotal = 0;
    float maxTemp = -9999, minTemp = 9999;
    float maxHum  = -9999, minHum  = 9999;

    char maxTempDate[20] = "-";
    char minTempDate[20] = "-";
    char maxHumDate[20]  = "-";
    char minHumDate[20]  = "-";

    char rainyDates[31][11]; // Max 31 rainy days in a month, "YYYY-MM-DD"
    int rainyCount = 0;

    int count = 0;

    Weather w;
    char dateStr[20];
    int dateNum;

    // File format: YYYY-MM-DD temp humidity rain
    while (fscanf(fp, "%19s %f %f %d",
                  dateStr, &w.temp, &w.humidity, &w.rain) != EOF) {

        // Parse date string into integers
        sscanf(dateStr, "%d-%d-%d", &w.year, &w.month, &w.day);

        // Filter by selected month and year
        if (w.month != inputMonth || w.year != inputYear)
            continue;

        // Convert this date to a number for easy comparison
        dateNum = dateToNumber(w.year, w.month, w.day);

        // Filter by selected day range (or full month)
        if (dateNum < fromNum || dateNum > toNum)
            continue;
```

---

## ❓ Teacher Might Ask You — WITH Answers

### **1️⃣ Why did you initialize max/min to extreme values?**

👉 So first real record always updates them.

### **2️⃣ Why rainyDates has size [31][11]?**

👉 Max 31 days, 10 chars for date + 1 null char = 11.

### **3️⃣ Why use fscanf?**

👉 It reads tokens in format:
`<date> <temp> <humidity> <rain>` automatically.

### **4️⃣ Why continue instead of nested if?**

👉 Cleaner code: skip immediately when mismatch.

### **5️⃣ Why convert date to number?**

👉 Makes range checks simple integer comparisons.

---

# 📈 **DEEKSHITHA — CALCULATIONS: MAX/MIN/AVG + RAINY LIST**

## 🔢 Code

```c
        // ---- Temperature calculations ----
        if (w.temp > maxTemp) {
            maxTemp = w.temp;
            strcpy(maxTempDate, dateStr);
        }

        if (w.temp < minTemp) {
            minTemp = w.temp;
            strcpy(minTempDate, dateStr);
        }

        tempTotal += w.temp;

        // ---- Humidity calculations ----
        if (w.humidity > maxHum) {
            maxHum = w.humidity;
            strcpy(maxHumDate, dateStr);
        }

        if (w.humidity < minHum) {
            minHum = w.humidity;
            strcpy(minHumDate, dateStr);
        }

        humidTotal += w.humidity;

        // ---- Rainy days tracking ----
        if (w.rain == 1 && rainyCount < 31) {
            strncpy(rainyDates[rainyCount], dateStr, 10);
            rainyDates[rainyCount][10] = '\0'; // ensure string end
            rainyCount++;
        }

        count++;
    } // end while loop

    fclose(fp);
```

---

## ❓ Teacher Might Ask You — WITH Answers

### **1️⃣ How do you ensure you don’t lose the date for max/min temp?**

👉 By using `strcpy()` whenever a new max/min is found.

### **2️⃣ Why keep total temp & humidity?**

👉 Needed for average calculation.

### **3️⃣ How is average calculated?**

👉 `tempTotal / count` and `humidTotal / count`.

### **4️⃣ Why check `rainyCount < 31`?**

👉 To prevent array overflow.

### **5️⃣ Why strncpy + null terminator?**

👉 Safe copying and guarantees valid string.

---

# 📝 **DISHANTH — FINAL REPORT + NO-DATA HANDLING**

## 🔢 Code

```c
    if (count == 0) {
        printf("\nNo data found for this month/range.\n");
        return 0;
    }

    printf("\n=========== Weather Report for %s ===========\n", location);
    printf("Month: %s  Year: %d\n", monthNames[inputMonth], inputYear);

    if (useRange)
        printf("Date Range: %d to %d\n", fromDay, toDay);
    else
        printf("Date Range: Entire Month\n");

    printf("\nTemperature:\n");
    printf("  Max: %.2f on %s\n", maxTemp, maxTempDate);
    printf("  Min: %.2f on %s\n", minTemp, minTempDate);
    printf("  Avg: %.2f\n", tempTotal / count);

    printf("\nHumidity:\n");
    printf("  Max: %.2f on %s\n", maxHum, maxHumDate);
    printf("  Min: %.2f on %s\n", minHum, minHumDate);
    printf("  Avg: %.2f\n", humidTotal / count);

    printf("\nRainy Days (%d days):\n", rainyCount);
    if (rainyCount == 0) {
        printf("  No rainy days in this range.\n");
    } else {
        for (int i = 0; i < rainyCount; i++) {
            printf("  %s\n", rainyDates[i]);
        }
    }

    printf("\n=============================================\n");

    return 0;
}
```

---

## ❓ Teacher Might Ask You — WITH Answers

### **1️⃣ What happens if there are no matching records?**

👉 Print: *“No data found for this month/range.”*

### **2️⃣ How did you print month name instead of number?**

👉 Using `monthNames[inputMonth]`.

### **3️⃣ How are averages printed?**

👉 `tempTotal / count` and `humidTotal / count`.

### **4️⃣ Why print dates with max/min?**

👉 To show *when* extreme values occurred.

### **5️⃣ How do you handle zero rainy days?**

👉 Print: *“No rainy days in this range.”*

---

