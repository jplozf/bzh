# ZUI
*A Simple NCurses UI Framework*
---
### ZApplication

### ZScreen

### ZInput

### ZLabel

### Example
```
int main(int argc, char *argv[]) {
    ZScreen mainScreen = ZScreen();
    ZInput txtPrompt = ZInput();
    mainScreen.addField(txtPrompt);
    ZApplication app = ZApplication(mainScreen);
    int rc = app->start();

    return rc;
}
```

### ZBoard
### ZTitle
### ZHeader
### ZRows
### ZRow
### ZPrompt
### ZFooter
### ZStatusbar
