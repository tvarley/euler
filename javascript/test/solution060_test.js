var assert = require('assert');
var solution060 = require('../src/euler/solution060');

describe('Solution060', function() {
  describe('answer', function() {
    it('will answer problem 060', function() {
      // This might be slow, so we can increase timeout if needed or just assert
      this.timeout(10000); 
      assert.equal(solution060.answer(), 26033);
    });
  });
});
