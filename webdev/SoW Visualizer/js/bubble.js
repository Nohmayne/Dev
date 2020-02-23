class Bubble {
    constructor(x, y, r, name="") {
        this.x = x;
        this.y = y;
        this.r = r;
        this.name = name;
    }

    show() {
        fill(255, 255, 255, 25);
        stroke(180, 55, 100);
        strokeWeight(4);
        circle(this.x, this.y, this.r);

        noStroke();
        fill(180, 55, 100);
        textSize(this.r / (PI * 1.5));
        textAlign(CENTER, CENTER);
        text(this.name, this.x, this.y);
    }
}
