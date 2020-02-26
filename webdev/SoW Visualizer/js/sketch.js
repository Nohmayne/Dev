let bubbles, lines;
let dragIndex = 0;
let selectedLine = 0;
let viewing = false;

let analyses = [
    "The connection Shinji and Hatsue share in The Sound of Waves reveals throughout the novel Shinji's inner desire to explore what life has to offer in spite of his initial simple outlook. Shinji's new knowledge after learning more about Hatsue's origins from Jukichi expands his view of the world, and prompts him to start wondering about the world outside of Uta-jima. This also expands the scope of the novel, making it not just about love, but about Shinji's coming of age. Shinji's peaceful feeling in the hands of mother nature when going to meet Hatsue highlights a parallel between Hatsue and nature, underscoring how both lovers feel it is only fate that they end up together. The setting of their meetings in nature and the further \"approval\" of outside forces when the generator turns back on further confirms this link.",
    "Yasuo's interactions with Shinji often end up working against him, instead working in Shinji's favor, a bit of irony used to underscore the virtues of honesty and hard work by contrasting them against the poor results of Yasuo's actions. Shinji's virtue is further demonstrated when he makes amends with Yasuo in spite of their direct competition over Hatsue. Yasuo is one of the very few true \"villains\" in the story, making the effect even greater when they ultimately bury the hatchet. Shinji's silent yet hard work abord the Utajima-maru epitomizes his virtuosness. On the other hand, Yasuo's laziness is made even clearer during his stay on the Utajima-maru, and the contrast built between his and Shinji's personalities makes it clear who will eventually marry Hatsue.",
    ""
];

function setup() {
    createCanvas(1000, 600);

    bubbles = [];
    bubbles.push(new Bubble(width/2, height/2, 100, "Shinji"));
    bubbles.push(new Bubble(width / 2 - 150, height / 2, 85, "Hatsue"));
    bubbles.push(new Bubble(width / 2, height / 2 + 175, 75, "Yasuo"));
    bubbles.push(new Bubble(width / 2 + 150, height / 2 - 185, 80, "Terukichi"));
    
    lines = [];
    for (let i = 1; i < bubbles.length; i++) { 
            lines.push(new Line(bubbles[0], bubbles[i], 5));
    }
}

function draw() {
    background(0);

    if (viewing) {
        for (let i = 0; i < bubbles.length; i++) {
            bubbles[i].show();
        }

        fill(0, 0, 0, 225);
        stroke(180, 55, 100);
        strokeWeight(4);
        rect(100, 100, width - 100, height - 100);

        noStroke();
        fill(255);
        textAlign(LEFT, TOP);
        textSize(24);
        text(analyses[selectedLine], 120, 120, width - 120, height - 120);
    } else {
        let dist = sqrt((mouseX - lines[0].x1) * (mouseX - lines[0].x1) + (mouseY - lines[0].y1) * (mouseY - lines[0].y1));
        selectedLine = 0;
        for (let i = 0; i < lines.length; i++) {
            lines[i].show();
            lines[i].color = color(180, 55, 100);

            let dx = mouseX - lines[i].x1;
            let dy = mouseY - lines[i].y1;
            let newDist = sqrt(dx * dx + dy * dy);

            if (newDist < dist) {
                selectedLine = i;
                dist = newDist;
            }
        }

        lines[selectedLine].color = color(255);

        for (let i = 0; i < bubbles.length; i++) {
            bubbles[i].show();
        }
    }

    
}

function mousePressed() {
    viewing = true;
}

function keyPressed() {
    if (keyCode === ESCAPE && viewing) {
        viewing = false;
    }
}
