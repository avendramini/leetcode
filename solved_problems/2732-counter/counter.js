/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    counter=-1
    return function() {
        counter+=1
        return counter+n
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */