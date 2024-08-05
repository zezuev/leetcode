import java.util.ArrayList;


class Item {
    int val;
    int min;

    public Item(int val, int min) {
        this.val = val;
        this.min = min;
    }
}


class MinStack {
    private ArrayList<Item> content;

    public MinStack() {
        content = new ArrayList<>();
    }

    public void push(int val) {
        if (content.isEmpty()) {
            content.add(new Item(val, val));
        } else {
            int min = Math.min(val, content.getLast().min);
            content.add(new Item(val, min));
        }
    }

    public void pop() {
        if (!content.isEmpty()) {
            content.removeLast();
        }
    }

    public int top() {
        if (!content.isEmpty()) {
            return content.getLast().val;
        }
        throw new IllegalStateException("Stack is empty");
    }

    public int getMin() {
        if (!content.isEmpty()) {
            return content.getLast().min;
        }
        throw new IllegalStateException("Stack is empty");
    }
}