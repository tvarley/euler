var assert = require('assert');
var solution029 = require('../src/euler/solution029');

describe('Solution029', function() {
  describe('answer', function() {
    it('will answer problem 029', function() {
      assert.equal(solution029.answer(), 9183);
    });
  });
});
