class Line {
    constructor(bubble1, bubble2, width) {
        this.color = color(180, 55, 100);
        this.selected = false;
        
        this.bubble1 = bubble1;
        this.bubble2 = bubble2;
        
        let betweenVector = createVector(this.bubble2.x - this.bubble1.x, this.bubble2.y - this.bubble1.y);
        betweenVector.normalize();

        this.x1 = this.bubble1.x + (this.bubble1.r / 2 * betweenVector.x);
        this.y1 = this.bubble1.y + (this.bubble1.r / 2 * betweenVector.y);

        this.x2 = this.bubble2.x - (this.bubble2.r / 2 * betweenVector.x);
        this.y2 = this.bubble2.y - (this.bubble2.r / 2 * betweenVector.y);
        
        this.width = width;

        this.c = this.y1;
        this.m = (this.y2 - this.y1) / (this.x2 - this.x1);
    }

    show() {
        stroke(this.color);
        strokeWeight(this.width);
        line(this.x1, this.y1, this.x2, this.y2);
    }
}
