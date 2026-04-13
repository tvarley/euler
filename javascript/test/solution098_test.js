var assert = require('assert');
var solution098 = require('../src/euler/solution098');

describe('Solution098', function() {
  describe('answer', function() {
    it('will answer problem 098', function() {
      assert.equal(solution098.answer(), 18769);
    });
  });
});