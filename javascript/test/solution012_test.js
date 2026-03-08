var assert = require('assert');
var solution012 = require('../src/euler/solution012');

describe('Solution012', function() {
  describe('answer', function() {
    it('will answer problem 012', function() {
      assert.equal(solution012.answer(), 76576500);
    });
  });
});