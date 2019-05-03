var assert = require('assert');
var solution006 = require('../src/euler/solution006');

describe('Solution006', function() {
  describe('answer', function() {
    it('will answer problem 006', function() {
      assert.equal(solution006.answer(), 25164150);
    });
  });
});
