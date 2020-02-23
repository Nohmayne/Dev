class Line {
    constructor(bubble1, bubble2, width) {
        this.bubble1 = bubble1;
        this.bubble2 = bubble2;

        let angle = atan((this.bubble2.y - this.bubble1.y) / (this.bubble2.x - this.bubble1.x));

        this.x1 = this.bubble1.x - (this.bubble1.r / 2) * cos(angle); 
        this.y1 = this.bubble1.y;

        this.x2 = this.bubble2.x;
        this.y2 = this.bubble2.y;

        this.width = width;
        this.id = "" + this.bubble1.name + "-" + this.bubble2.name;

        console.log(this.id + "  " + angle);
    }

    show() {
        stroke(180, 55, 100);
        strokeWeight(this.width);
        line(this.x1, this.y1, this.x2, this.y2);
    }

    calculateLines() {

    }
}
