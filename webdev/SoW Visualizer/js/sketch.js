let bubbles, lines;
let dragIndex = 0;
let selectedLine = 0;
let viewing = false;
let bg;

let analyses = [
    "The connection Shinji and Hatsue share in The Sound of Waves reveals throughout the novel Shinji's inner desire to explore what life has to offer in spite of his initial simple outlook. Shinji's new knowledge after learning more about Hatsue's origins from Jukichi expands his view of the world, and prompts him to start wondering about the world outside of Uta-jima. This also expands the scope of the novel, making it not just about love, but about Shinji's coming of age. Shinji's peaceful feeling in the hands of mother nature when going to meet Hatsue highlights a parallel between Hatsue and nature, underscoring how both lovers feel it is only fate that they end up together. The setting of their meetings in nature and the further \"approval\" of outside forces when the generator turns back on further confirms this link.",
    "Yasuo's interactions with Shinji often end up working against him, instead working in Shinji's favor, a bit of irony used to underscore the virtues of honesty and hard work by contrasting them against the poor results of Yasuo's actions. Shinji's virtue is further demonstrated when he makes amends with Yasuo in spite of their direct competition over Hatsue. Yasuo is one of the very few true \"villains\" in the story, making the effect even greater when they ultimately bury the hatchet. Shinji's silent yet hard work abord the Utajima-maru epitomizes his virtuosness. On the other hand, Yasuo's laziness is made even clearer during his stay on the Utajima-maru, and the contrast built between his and Shinji's personalities makes it clear who will eventually marry Hatsue.",
<<<<<<< HEAD
    ""
=======
    "Terukichi consistently separating Hatsue and Shinji throughout most of The Sound of Waves creates a barrier to test both Shinji's resolve and his love for Hatsue. Their persistent attempts to communicate and meet against his will show the strength of their connection, which highlights Shinji's hidden desire for more than what he has, in spite of his simple outlook on life. Uncle Teru also serves as a force to push Yasuo and Shinji further apart in their behavior, exacerbating their differences to the point where Yasuo's true personality of laziness and apathy becomes known to everyone. Taking in both Shinji and Yasuo as apprentices on his ship shows Terukichi's consideration of his daughters feelings in spite of his repeated denial of her wishes to see Shinji. The apprenticeship for Shinji is not necessarily a chance to win Terukichi's respect and Hatsue's hand, but also a chance to see the world outside of Uta-jima. Although he does find joy in traveling and seeing sights, ultimately it is Shinji's showing of bravery, conviction, and \"get up and go\" attitude that makes the trip significant.",
    "Test2",
    "Test3"
>>>>>>> 8f2f18171e9a65664458c7dccba63fc414b05398
];

function preload() {
    bg = loadImage('https://upload.wikimedia.org/wikipedia/commons/thumb/0/0a/The_Great_Wave_off_Kanagawa.jpg/1024px-The_Great_Wave_off_Kanagawa.jpg');
}

function setup() {
    createCanvas(1024, 706);

    bubbles = [];
    bubbles.push(new Bubble(width/2, height/2, 100, "Shinji"));
    bubbles.push(new Bubble(width / 2 - 150, height / 2, 85, "Hatsue"));
    bubbles.push(new Bubble(width / 2, height / 2 + 175, 75, "Yasuo"));
    bubbles.push(new Bubble(width / 2 + 150, height / 2 - 185, 80, "Terukichi"));
    bubbles.push(new Bubble(width / 2 - 125, height / 2 - 135, 80, "Chiyoko"));

    lines = [];
<<<<<<< HEAD
    for (let i = 1; i < bubbles.length; i++) { 
            lines.push(new Line(bubbles[0], bubbles[i], 5));
=======
    for (let i = 1; i < bubbles.length; i++) {
        lines.push(new Line(bubbles[0], bubbles[i], 4));
>>>>>>> 8f2f18171e9a65664458c7dccba63fc414b05398
    }
    lines.push(new Line(bubbles[1], bubbles[2], 4));

}

function draw() {
    background(bg);

    if (viewing) {
        for (let i = 0; i < bubbles.length; i++) {
            bubbles[i].show();
        }

        fill(0, 0, 0, 225);
        stroke(50, 75, 150);
        strokeWeight(4);
        rect(50, 50, width-100, height-100);

        noStroke();
        fill(255);
        textAlign(LEFT, TOP);
        textSize(24);
        text(analyses[selectedLine], 75, 75, width - 125, height - 125);
    } else {
        selectedLine = detectClosestLine();

        for (let i = 0; i < lines.length; i++) {
            lines[i].show();
            lines[i].color = color(50, 75, 150);
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

function detectClosestLine() {
    let index = 0;
    let dx = abs(mouseX - (lines[index].x1 + lines[index].x2) / 2);
    let dy = abs(mouseY - (lines[index].y1 + lines[index].y2) / 2);
    let dist = sqrt(dx * dx + dy * dy);
    
    for (let i = 1; i < lines.length; i++) {
        dx = abs(mouseX - (lines[i].x1 + lines[i].x2) / 2);
        dy = abs(mouseY - (lines[i].y1 + lines[i].y2) / 2);

        let newDist = sqrt(dx * dx + dy * dy);
        if (newDist < dist) {
            index = i;
            dist = newDist;
        }
    }

    return index;
}
