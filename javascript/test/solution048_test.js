var assert = require('assert');
var solution048 = require('../src/euler/solution048');

describe('Solution048', function() {
  describe('answer', function() {
    it('will answer problem 048', function() {
      assert.equal(solution048.answer(), 9110846700);
    });
  });
});