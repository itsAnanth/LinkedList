class ListNode {
    constructor(value, next) {
        this.data = value;
        this.next = !next ? null : next;
    }
}

class LinkedList {
    #head;
    constructor() {
        this.#head = null;
    }

    push(value) {
        const newNode = new ListNode(value);
        let temp = this.#head;
        if (!temp) {
            this.#head = newNode
            return;
        }

        while (temp.next) {
            temp = temp.next;
        }

        temp.next = newNode;
    } 

    unshift(value) {
        const newNode = new ListNode(value);
        newNode.next = this.#head;
        this.#head = newNode;
    }


    print() {
        let current = this.#head;
        if (!this.#head) return console.log('This is an empty list');
        while (current) {
            console.log(current.data);
            current = current.next;
        }
    }


    reverse() {
        let current = this.#head;
        let previous = null;
        let temp = null;

        while (current) {
            temp = current.next;
            current.next = previous;
            previous = current;
            current = temp;
        }

        this.#head = previous
    }
}


const list = new LinkedList();

list.push(1);
list.push(5);
list.push(2);
list.unshift(0);
list.reverse();
list.push(10);
list.print();
