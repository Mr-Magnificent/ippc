// let set = new Set(a);

let perm = new Set();
let arr = [new Set(), new Set(), new Set()];

recursion(0, 0);
function recursion(num, d) {
    if (d == 4) {
        let count = 0;
        let temp = num;
        let div = 1000;
        let maxNum = -1;
        while (temp != 0) {
            const quo = Number(temp / div).toFixed(0);
            if (quo > maxNum) {
                maxNum = quo;
                count++;
            }
            temp %= div;
            div /= 10;
        }
        if (count == 2) {
            perm.add(num);
            arr[maxNum - 1].add(num);
        }

        return;
    }

    for (let i = 1; i <= 3; ++i) {
        recursion(num * 10 + i, d + 1);
    }
}

// set.forEach((val) => perm.delete(val));

console.log(perm);
console.log(perm.size);
console.log();
arr.forEach((ele) => console.log(ele));