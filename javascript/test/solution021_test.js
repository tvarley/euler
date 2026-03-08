var assert = require('assert');
var solution021 = require('../src/euler/solution021');

describe('Solution021', function() {
  describe('answer', function() {
    it('will answer problem 021', function() {
      assert.equal(solution021.answer(), 31626);
    });
  });
});