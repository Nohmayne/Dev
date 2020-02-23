let bubbles, lines;

function setup() {
    createCanvas(1000, 600);

    bubbles = [];
    bubbles.push(new Bubble(width/2, height/2, 100, "Shinji"));
    bubbles.push(new Bubble(width / 2 - 150, height / 2, 85, "Hatsue"));
    bubbles.push(new Bubble(width / 2, height / 2 + 175, 75, "Yasuo"));
    bubbles.push(new Bubble(width / 2 + 150, height / 2 - 185, 80, "Terukichi"));
    
    lines = [];
    lines.push(new Line(bubbles[1], bubbles[2], 5));
    //for (let i = 0; i < bubbles.length - 1; i++) {
    //    for (let j = i + 1; j < bubbles.length; j++) {
    //        lines.push(new Line(bubbles[i], bubbles[j], 5));
    //    }
    //}
}

function draw() {
    background(0);

    for (let i = 0; i < bubbles.length; i++) {
        bubbles[i].show();
    }

    for (let i = 0; i < lines.length; i++) {
        lines[i].show();
    }
}
