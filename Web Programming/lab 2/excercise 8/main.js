var inputField = document.getElementById('inputField')
var normalBtns = document.getElementsByClassName('normalBtn');
var clearBtn = document.getElementById('clearBtn');
var submitBtn = document.getElementById('submitBtn');
var themeSelect = document.getElementById('theme');
var themeLink = document.getElementById('themeLink');


// Set id for btn
for (btn of normalBtns) {
    btn.id = btn.innerText;
}

function addText(sometext) {
    inputField.value += sometext;
}

function clearInput() {
    inputField.value = "";
}

function changeTheme() {
    var chosenTheme = themeSelect.options[themeSelect.selectedIndex].text;

    if (chosenTheme === 'Default') {
        themeLink.href = 'ex8_normal.css';
    }
    else {
        themeLink.href = (chosenTheme === 'Dark') ? 'ex8_dark.css' : 'ex8_color.css';
    }
}

function getInput() {
    var input = inputField.value;
    var formatInput = input.replace('X', '*');

    try {
        var result = eval(formatInput);
    } catch (error) {

        var result = String(error);
        var result = result.split(':')[0];
    }

    clearInput();

    inputField.value = result;
}

function funcBtn() {
    for (btn of normalBtns) {
        var text = btn.id;
        btn.setAttribute('onClick', 'addText(\'' + text + '\')');
    }

    clearBtn.setAttribute('onClick', 'clearInput()');
    submitBtn.setAttribute('onClick', 'getInput()');
    themeSelect.setAttribute('onChange', 'changeTheme()');
}

funcBtn();