// Initialize MathQuill
let MQ = MathQuill.getInterface(2);

// Autosuggest vars
let doAutoSuggest = true;
let workingString = "";

// Make an answer field
let answerArea = document.getElementById('mField');
let answerMathField = MQ.MathField(answerArea, {
    leftRightIntoCmdGoes: 'up',
    charactersThatBreakOutOfSupSub: '+-=<>',
    restrictMismatchedBrackets: true,
    supSubsRequireOperand: true,
    autoCommands: 'pi theta sqrt sum int pm',
    autoOperatorNames: 'sin cos tan csc sec cot arcsin arccos arctan arccsc arcsec arccot min max lim',
});

document.addEventListener("keydown", event => {
    if (event.key === "\\") {
        doAutoSuggest = false;
    }
});