const test1 = require('bindings')('test1');
const test2 = require('bindings')('test2')
var test3 = require('bindings')('test3');

console.log('test1',test1.hello());
console.log('test1',test1.sum(1,2));
const arr = [3, 5, 2, 7, 1, 8, 4, 6];
console.log('test1',test1.quickSort(arr));


console.log('test2',test2.hello())
console.log('test3',test3.hello())













