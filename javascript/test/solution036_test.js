var assert = require('assert');
var solution036 = require('../src/euler/solution036');

describe('Solution036', function() {
  describe('answer', function() {
    it('will answer problem 036', function() {
      assert.equal(solution036.answer(), 872187);
    });
  });
});