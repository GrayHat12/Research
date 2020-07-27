class Connection {
    weight;
    value;
    constructor() {
        this.weight = Math.random() * 2 - 1;
    }
    feed(value) {
        this.value = value * this.weight;
    }
}