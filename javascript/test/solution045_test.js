var assert = require('assert');
var solution045 = require('../src/euler/solution045');

describe('Solution045', function() {
  describe('answer', function() {
    it('will answer problem 045', function() {
      assert.equal(solution045.answer(), 1533776805);
    });
  });
});